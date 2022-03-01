#include "stdafx.h"
#include "FirstScene.h"

void FirstScene::Start()
{
	GetPlayer->Start();

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

	std::random_device rd;

	std::mt19937 gen(rd());

	std::uniform_int_distribution<int> dis(4, 10);

	for (int i = 0; i < dis(gen); i++) {
		enemies.push_back(new Enemy);
	}

	for (auto e : enemies)
	{
		e->Start();
	}

	BulletPooling = new ObjectPool();
}

bool FirstScene::Update()
{
	BG.Draw();

	GetPlayer->Update();
	
	if (Input::Get::Key::Down(0x31)) BGmusic.Pause();

	if (Input::Get::Key::Down(VK_LBUTTON) && !GetPlayer->IsRoll())
	{
		float x = static_cast<float>(Input::Get::Cursor::X());
		float y = static_cast<float>(Input::Get::Cursor::Y());

		x = x - 1280 / 2;
		y = -(y - 720 / 2);

		vector<2> dir = { x, y };

		auto bullet =
			BulletPooling->GetRecycledObject<Bullet>();

		bullet->Shoot(GetPlayer->GetCharacter().Location, dir);
	}

	for (auto bullet : BulletPooling->PoolObjects)
	{
		for (auto e : enemies) {
			if (Collision::Collide(e->GetCharacterHitbox(), static_cast<Bullet*>(bullet)->GetBulletHitbox()))
			{
				static_cast<Bullet*>(bullet)->Shoot(GetPlayer->GetCharacter().Location, 0);
				bullet->SetRecycle();
				e->DealEnemyHP(static_cast<Bullet*>(bullet)->GetBulletDamage());
				std::cout << "hit" << std::endl;
			}
		}

		if (!static_cast<Bullet*>(bullet)->CanRecylcable)
			bullet->Update();
	}

	for (int i = 0; i<enemies.size(); i++)
	{
		if (enemies[i]->GetEnemyHP() == 0)
		{
			delete enemies[i];
			enemies.erase(enemies.begin() + i);
		}
	}

	for (auto e : enemies)
	{
		e->Update();
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

	Sound::EndPlay();
}
