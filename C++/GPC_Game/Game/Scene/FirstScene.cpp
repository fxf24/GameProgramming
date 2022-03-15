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
	
	for (int i = 0; i < 400; i++)
	{
		std::vector< Rendering::Tilemap::Component> floor;
		for (int j = 0; j < 400; j++) {
			floor.push_back( Rendering::Tilemap::Component("Dungeon_Tileset", 
				{32, 32}, 
				{-(1280 * 5)+ (j * 32), (1280 * 5) - (i * 32)},
				Rendering::Tilemap::Tile::Empty));
		}
		map.push_back(floor);
	}

	for (int i = 180; i < 223; i++)
	{
		map[188][i].tile = Rendering::Tilemap::Tile::Top_Wall;
		for (int j = 189; j < 214; j++)
		{
			map[j][i].tile = Rendering::Tilemap::Tile::Ground;
		}
		map[214][i].tile = Rendering::Tilemap::Tile::Bottom_Wall;
	}

	for (int i = 188; i < 214; i++)
	{
		map[i][179].tile = Rendering::Tilemap::Tile::Left_Wall;
		map[i][223].tile = Rendering::Tilemap::Tile::Right_Wall;
	}
}

bool FirstScene::Update()
{
	int curr_cam_i = static_cast<int>(Camera->Location[1] / 32);
	int	curr_cam_j = static_cast<int>(Camera->Location[0] / 32);

	int start_i = 188 - curr_cam_i;
	int start_j = 179 + curr_cam_j;

	for (int i = start_i; i < start_i + 26; i++)
	{
		for (int j = start_j; j < start_j + 44; j++)
		{
			if (map[i][j].tile == Rendering::Tilemap::Tile::Top_Wall 
				|| map[i][j].tile == Rendering::Tilemap::Tile::Right_Wall
				|| map[i][j].tile == Rendering::Tilemap::Tile::Left_Wall
				|| map[i][j].tile == Rendering::Tilemap::Tile::Bottom_Wall)
			{
				GetTilemanager->Init(
					map[i][j],
					GetPlayer->GetCharacter()
				);

				Collision::RectAngle wall{
					map[i][j].Length,
					0,
					map[i][j].Location
				};
				
				if (Collision::Collide(GetPlayer->GetCharacterHitbox(), wall))
				{
					GetTilemanager->TileRange();
				}
			}
			map[i][j].Draw();
		}
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
