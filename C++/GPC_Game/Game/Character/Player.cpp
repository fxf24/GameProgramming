#include "stdafx.h"
#include "Player.h"


void Player::Start()
{
	character.Content = "rogue_idle";
	character.Length = { (264 / 8) * 2, 34 * 2 };
	character.Location = { 0, 0 };
	character.Repeatable = true;
	character.Duration = 1.0f;
	character.view = View::idle;
}

bool Player::Update()
{
	vector<2> direction;

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

	if (length(direction) != 0)
	{
		character.Location += normalize(direction) * 500 * Time::Get::Delta();
		Cam.Location += normalize(direction) * 500 * Time::Get::Delta();
	}

	if (Input::Get::Key::Press(VK_SHIFT))
	{
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

		character.Duration = 0.3f;
		for (float t = 0; t < Time::Get::Delta() * 9; t += Time::Get::Delta())
		{
			character.Location += normalize(direction) * 500 * Time::Get::Delta();
			Cam.Location += normalize(direction) * 500 * Time::Get::Delta();
		}
	}
	else {
		character.Duration = 1.0f;
	}

	Cam.Set();
	character.Draw();

	return false;
}

void Player::End()
{
	//delete Instance;
}
