#include "stdafx.h"
#include "FirstScene.h"
using namespace Rendering::Animation;

void FirstScene::Start()
{
	player->Start();

	Damage.Length = { 500, 200 };
	Damage.Location = { 250 , 100 };
	Damage.Font.Name = "KangWonAll_Bold";
	Damage.Font.Size = 50;
	Damage.Color = { 255, 255, 255 };
	Damage.str = "0";

	BG.Content = "background";
	BG.Length = { 1280 * 3, 720 * 3};

	BGmusic.Content = "BGM";
	BGmusic.volume = 0.1f;
	BGmusic.Play();

	enemies.push_back(new Enemy);
	for (auto e : enemies)
	{
		e->Start();
	}

	BulletPooling = new ObjectPool();
}

bool FirstScene::Update()
{
	BG.Draw();

	player->Update();
	for (auto e : enemies)
	{
		e->Update();
	}
	
	
	if (Input::Get::Key::Down(0x31)) BGmusic.Pause();

	if (Input::Get::Key::Down(VK_LBUTTON) && !player->IsRoll())
	{
		float x = static_cast<float>(Input::Get::Cursor::X());
		float y = static_cast<float>(Input::Get::Cursor::Y());

		x = x - 1280 / 2;
		y = -(y - 720 / 2);

		vector<2> dir = { x, y };

		auto bullet =
			BulletPooling->GetRecycledObject<Bullet>();

		bullet->Shoot(player->GetCharacter().Location, dir);
	}

	for (auto bullet : BulletPooling->PoolObjects)
	{
		bullet->Update();
	}

	Damage.Draw();
    return false;
}

void FirstScene::End()
{
	for (auto e : enemies)
	{
		delete e;
	}
}
