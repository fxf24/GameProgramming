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

	BG.Content = "background";
	BG.Length = { 1280 * 3, 720 * 3};

	BGmusic.Content = "BGM";
	BGmusic.volume = 0.5f;
	BGmusic.Play();
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
		Cam.Location += normalize(direction) * 500 * Time::Get::Delta();
	}

	char buf[256];
	int sum = atoi(Damage.str);
	if (Input::Get::Key::Press(VK_SHIFT))
	{
		switch (Player.view)
		{
		case View::idle:
			Player.Content = "rogue_dodge_right";
			break;
		case View::front:
			Player.Content = "rogue_dodge_front";
			break;
		case View::back:
			Player.Content = "rogue_dodge_back";
			break;
		}

		float elapsed = Time::Get::Elapsed();
		Player.Duration = 0.3f;
		for(float t = 0; t < Time::Get::Delta()*9; t += Time::Get::Delta())
		{
			Player.Location += normalize(direction) * 500 * Time::Get::Delta();
			Cam.Location += normalize(direction) * 500 * Time::Get::Delta();
		}
		elapsed = Time::Get::Elapsed();
		sprintf_s(buf, "%f", elapsed);
		Damage.str = buf;
	}
	else {
		Player.Duration = 1.0f;

		char buf[256];
		sprintf_s(buf, "%d", sum);
		Damage.str = buf;
	}

	BG.Draw();
	Cam.Set();
	Player.Draw();
	Damage.Draw();
    return false;
}

void TestScene::End()
{
}
