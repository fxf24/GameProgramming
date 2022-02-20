#include "stdafx.h"
#include "TestScene.h"
using namespace Rendering::Animation;

void TestScene::Start()
{
	Player.Content = "rogue_idle";
	Player.Length = { (264 / 8) * 2, 34 * 2 };
	Player.Location = { 0, 0 };
	Player.Repeatable = true;
	Player.Duration = 1.0f;
	Player.view = View::idle;

	Damage.Length = { 500, 200 };
	Damage.Location = { 250 , 100 };
	Damage.Font.Name = "KangWonAll_Bold";
	Damage.Font.Size = 50;
	Damage.Color = { 255, 255, 255 };
	Damage.str = "0";
}

bool TestScene::Update()
{
	vector<2> direction;

	switch (Player.view)
	{
	case View::idle:
		Player.Content = "rogue_idle";
		break;
	case View::front:
		Player.Content = "rogue_idle_front";
		break;
	case View::back:
		Player.Content = "rogue_idle_back";
		break;
	}


	if (Input::Get::Key::Press('a') || Input::Get::Key::Press('A'))
	{
		Player.view = View::idle;
		Player.Content = "rogue_run_forward";
		direction[0] -= 1;
		Player.direction = true;
	}
	if (Input::Get::Key::Press('d') || Input::Get::Key::Press('D'))
	{
		Player.view = View::idle;
		Player.Content = "rogue_run_forward";
		direction[0] += 1;
		Player.direction = false;
	}
	if (Input::Get::Key::Press('w') || Input::Get::Key::Press('W'))
	{
		Player.view = View::back;
		Player.Content = "rogue_run_back";
		direction[1] += 1;
	}
	if (Input::Get::Key::Press('s') || Input::Get::Key::Press('S'))
	{
		Player.view = View::front;
		Player.Content = "rogue_run_front";
		direction[1] -= 1;
	}

	if (length(direction) != 0)
	{
		Player.Location += normalize(direction) * 500 * Time::Get::Delta();
	}


	Cam.Set();
	Player.Draw();
	Damage.Draw();
    return false;
}

void TestScene::End()
{
}
