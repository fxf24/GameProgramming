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
	BG.Length = { 1280 * 10, 1280 * 10};

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

	Camera = new Rendering::Camera();
	GetCameraManager->Init(BG, GetPlayer->GetCharacter(), Camera);

	
	for (int i = 0; i < 400; i++)
	{
		map.push_back(std::vector<Rendering::Tilemap::Tile>(400, Rendering::Tilemap::Tile::Ground));
	}
	Tileset.Content = "Dungeon_Tileset";
	Tileset.Length = { 16*2, 16*2 };
	Tileset.Location = { 0, 0 };

	map[199][199] = Rendering::Tilemap::Tile::Wall;
	map[199][200] = Rendering::Tilemap::Tile::Wall;
	map[200][199] = Rendering::Tilemap::Tile::Wall;
	map[200][200] = Rendering::Tilemap::Tile::Wall;


	map[209][209] = Rendering::Tilemap::Tile::Wall;
	map[209][210] = Rendering::Tilemap::Tile::Wall;
	map[210][209] = Rendering::Tilemap::Tile::Wall;
	map[210][210] = Rendering::Tilemap::Tile::Wall;
}

bool FirstScene::Update()
{
	BG.Draw();

	int curr_cam_i = static_cast<int>(Camera->Location[1] / 32);
	int	curr_cam_j = static_cast<int>(Camera->Location[0] / 32);

	int start_i = 188 - curr_cam_i;
	int start_j = 179 + curr_cam_j;

	/*std::cout << (Tileset.Location != vector<2>(-32 * 21 + static_cast<int>(Camera->Location[0]), 32 * 12 + static_cast<int>(Camera->Location[1]))) << std::endl;*/
	
	Tileset.Location = { -32 * 21 + static_cast<int>(Camera->Location[0]), 32 * 12 + static_cast<int>(Camera->Location[1]) };
	for (int i = start_i; i < start_i + 24; i++)
	{
		for (int j = start_j; j < start_j + 42; j++)
		{
			Tileset.Location += vector<2>(32, 0);
			Tileset.Draw(map[i][j]);
		}
		Tileset.Location -= vector<2>(32 * 42, 32);
	}

	Camera->Set();
	GetPlayer->Update();

	if (Input::Get::Key::Down(0x31)) BGmusic.Pause();

	if (Input::Get::Key::Down(VK_LBUTTON) && !GetPlayer->IsRoll())
	{
		float x = static_cast<float>(Input::Get::Cursor::X());
		float y = static_cast<float>(Input::Get::Cursor::Y());
		
		x = x - 1280 / 2;
		y = -(y - 720 / 2);

		vector<2> dir = { x, y };

		dir -= (GetPlayer->GetCharacter()->Location - Camera->Location);

		auto bullet =
			BulletPooling->GetRecycledObject<Bullet>();

		bullet->Shoot(GetPlayer->GetCharacter()->Location, dir);
	}

	for (auto bullet : BulletPooling->PoolObjects)
	{
		for (auto e : enemies) {
			if (Collision::Collide(e->GetCharacterHitbox(), static_cast<Bullet*>(bullet)->GetBulletHitbox()))
			{
				static_cast<Bullet*>(bullet)->Shoot(GetPlayer->GetCharacter()->Location, 0);
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

	float x = static_cast<float>(Input::Get::Cursor::X());
	float y = static_cast<float>(Input::Get::Cursor::Y());
	if (x < 150 || x > 1130 || y < 150 || y > 570)
	{
		x = x - 1280 / 2;
		y = -(y - 720 / 2);

		vector<2> dir = { x, y };
		if ((Camera->Location[0] <= GetPlayer->GetCharacter()->Location[0] + 150 && Camera->Location[0] >= GetPlayer->GetCharacter()->Location[0] - 150)
			&& (Camera->Location[1] >= GetPlayer->GetCharacter()->Location[1] - 150 && Camera->Location[1] <= GetPlayer->GetCharacter()->Location[1] + 150))
		{
			Camera->Location += normalize(dir) * 700 * Time::Get::Delta();
			std::cout << "Cam Location :" << Camera->Location[0] << " : " << Camera->Location[1] << std::endl;
		}
	}
	else {
		if (!(Camera->Location[0] <= GetPlayer->GetCharacter()->Location[0] + 1 && Camera->Location[0] >= GetPlayer->GetCharacter()->Location[0] - 1)
			|| !(Camera->Location[1] <= GetPlayer->GetCharacter()->Location[1] + 1 && Camera->Location[1] >= GetPlayer->GetCharacter()->Location[1] - 1))
		{
			vector<2> dir = GetPlayer->GetCharacter()->Location - Camera->Location;
			Camera->Location += normalize(dir) * 1000 * Time::Get::Delta();
		}
	}
	
	GetCameraManager->CameraRange();
	Damage.Draw();
    return false;
}

void FirstScene::End()
{
	for (auto e : enemies)
	{
		delete e;
	}
	GetCameraManager->DeInit();
	Sound::EndPlay();
}
