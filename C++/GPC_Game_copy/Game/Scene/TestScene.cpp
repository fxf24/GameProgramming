#include "stdafx.h"
#include "TestScene.h"

void TestScene::Start()
{
    Player.Content = "Amongus";
    Player.Length = { 1008 / 12, 120 };
    Player.Location = { 0, 0 };
    Player.Repeatable = true;
    Player.Duration = 0.5f;

	monster.Content = "Sonic";
	monster.Length = { (1404 / 9)/2, 160/2 };
	monster.Location = { 100, 100 };
	monster.Repeatable = true;
	monster.Duration = 1.0f;

	Damage.Length = { 500, 200 };
	Damage.Location = { 250 , 100 };
	Damage.Font.Name = "KangWonAll_Bold";
	Damage.Font.Size = 50;
	Damage.Color = { 255, 255, 255 };
	Damage.str = "0";

	BulletPooling = new ObjectPool();
}

bool TestScene::Update()
{
	vector<2> direction;

	if (Input::Get::Key::Press(VK_LEFT)) 
	{
		direction[0] -= 1;
		Player.direction = true;
	}
	if (Input::Get::Key::Press(VK_RIGHT))
	{
		direction[0] += 1;
		Player.direction = false;
	}
	if (Input::Get::Key::Press(VK_UP))    direction[1] += 1;
	if (Input::Get::Key::Press(VK_DOWN))  direction[1] -= 1;


	if (length(direction) != 0)
	{
		Player.Location += normalize(direction) * 500 * Time::Get::Delta();
		Cam.Location += normalize(direction) * 500 * Time::Get::Delta();
	}

	if (Input::Get::Key::Down('a') || Input::Get::Key::Down('A') && length(direction) != 0)
	{
		auto bullet = static_cast<Bullet*>(BulletPooling->GetRecycledObject());

		if (!bullet)
		{
			BulletPooling->RegisterObject(bullet = new Bullet);
			Bullets.push_back(bullet);
		}

		bullet->Shoot(Player.Location, direction);
	}

	for (auto bullet : Bullets)
	{
		if (!bullet->GetCanRecycle())
			bullet->Update();
	}

	Collision::RectAngle p = {
		Player.Length,
		Player.Angle,
		Player.Location
	};

	Collision::RectAngle m = {
		monster.Length,
		monster.Angle,
		monster.Location
	};

	int sum = atoi(Damage.str);
	if (Collision::Collide(p, m)) {
		sum += 5;
		char buf[256];
		sprintf_s(buf, "%d", sum);
		Damage.str = buf;
	}
	else {
		char buf[256];
		sprintf_s(buf, "%d", sum);
		Damage.str = buf;
	}

	if (Input::Get::Key::Down('W')) GetSceneManger->ChangeScene("BGScene");
	if (Input::Get::Key::Down(VK_ESCAPE)) 
		return false;

	Cam.Set();
	Player.Draw();
	monster.Draw();
	Damage.Draw();
    return true;
}

void TestScene::End()
{
}
