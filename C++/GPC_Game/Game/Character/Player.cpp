#include "stdafx.h"
#include "Player.h"
#include <iostream>
using namespace Rendering::Animation;

void Player::Start()
{
	character.Content = "rogue_idle";
	character.Length = { (264 / 8) * 2, 34 * 2 };
	character.Location = { 0, 0 };
	character.Repeatable = true;
	character.Duration = 1.0f;
	character.view = View::idle;


	for (int i = 0; i < 10; i++)
	{
		pool.push(new Bullet);
	}
}

bool Player::Update()
{
	vector<2> direction;
	
	if (!isRoll) 
	{
		switch (character.view)
		{
		case View::idle:
			character.Content = "rogue_idle";
			break;
		case View::front:
			character.Content = "rogue_idle_front";
			break;
		case View::back:
			character.Content = "rogue_idle_back";
			break;
		}	

		if (Input::Get::Key::Press('a') || Input::Get::Key::Press('A'))
		{
			character.view = View::idle;
			character.Content = "rogue_run_forward";
			direction[0] -= 1;
			character.direction = true;
		}
		if (Input::Get::Key::Press('d') || Input::Get::Key::Press('D'))
		{
			character.view = View::idle;
			character.Content = "rogue_run_forward";
			direction[0] += 1;
			character.direction = false;
		}
		if (Input::Get::Key::Press('w') || Input::Get::Key::Press('W'))
		{
			character.view = View::back;
			character.Content = "rogue_run_back";
			direction[1] += 1;
		}
		if (Input::Get::Key::Press('s') || Input::Get::Key::Press('S'))
		{
			character.view = View::front;
			character.Content = "rogue_run_front";
			direction[1] -= 1;
		}
	}

	if (isRoll)
	{
		character.Duration = 0.5f;
		character.Location += normalize(roll_direction) * 1000 * Time::Get::Delta();
		Cam.Location += normalize(roll_direction) * 1000 * Time::Get::Delta();
		
		character.rollTime += Time::Get::Delta();

		if (character.rollTime >= character.Duration)
		{
			character.rollTime = 0;
			isRoll = false;
			character.Duration = 1.0f;
		}
	}
	
	if (length(direction) != 0 && !isRoll) 
	{
		character.Location += normalize(direction) * 500 * Time::Get::Delta();
		Cam.Location += normalize(direction) * 500 * Time::Get::Delta();
	}

	if (Input::Get::Key::Down(VK_SHIFT) && length(direction) != 0)
	{
		isRoll = true;
		switch (character.view)
		{
		case View::idle:
			character.Content = "rogue_dodge_right";
			break;
		case View::front:
			character.Content = "rogue_dodge_front";
			break;
		case View::back:
			character.Content = "rogue_dodge_back";
			break;
		}
		roll_direction = direction;
	}

	if (Input::Get::Key::Down(VK_LBUTTON) && !isRoll)
	{
		float x = static_cast<float>(Input::Get::Cursor::X());
		float y = static_cast<float>(Input::Get::Cursor::Y());

		/*x -= character.Location[0];
		y -= character.Location[1];*/

		vector<2> dir = { x, y };
		Bullet* b = pool.front();
		b->SetLocation(character.Location);
		b->SetBulletDirection(normalize(dir));
		bullet.push_back(b);
		bullet.back()->Start();
		pool.pop();
	}
	
	for (auto b : bullet)
	{
		b->Update();
	}

	Cam.Set();
	character.Draw();

	return false;
}

void Player::End()
{
	//delete Instance;
}
