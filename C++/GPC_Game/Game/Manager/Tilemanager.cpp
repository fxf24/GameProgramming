#include "stdafx.h"
#include "Tilemanager.h"
#include "Character/Player.h"

void Tilemanager::Init(Rendering::Tilemap::Component t, Rendering::Animation::Component* pl)
{
	Tile = t;
	Player = pl;
	
}

void Tilemanager::TileRange()
{
	if (Player->Angle != 0.0f and Tile.Angle != 0.0f) return;

	vector<2> const min[2]
	{
		Player->Location - Player->Length / 2,
		Tile.Location - Tile.Length / 2,
	};

	vector<2> const max[2]
	{
		Player->Location + Player->Length / 2,
		Tile.Location + Tile.Length / 2,
	};

	vector<2> direction = GetPlayer->GetCurrDirection();
	vector<2> roll_direction = GetPlayer->GetRollDirection();

	if (min[0][0] <= max[1][0] && (direction[0] == -1 || roll_direction[0] == -1))
	{ 
		if (GetPlayer->IsRoll())
		{
			Player->Location[0] += 1.0f * 700 * Time::Get::Delta();
		}
		else
		{
			Player->Location[0] += 1.0f * 500 * Time::Get::Delta();
		}
	}
	if (max[0][0] >= min[1][0] && (direction[0] == 1 || roll_direction[0] == 1))
	{
		if (GetPlayer->IsRoll())
		{
			Player->Location[0] -= 1.0f * 700 * Time::Get::Delta();
		}
		else
		{
			Player->Location[0] -= 1.0f * 500 * Time::Get::Delta();
		}
	}
	if (min[0][1] <= max[1][1] && (direction[1] == -1 || roll_direction[1] == -1))
	{
		if (GetPlayer->IsRoll())
		{
			Player->Location[1] += 1.0f * 700 * Time::Get::Delta();
		}
		else
		{
			Player->Location[1] += 1.0f * 500 * Time::Get::Delta();
		}
	}
	if (max[0][1] >= min[1][1] && (direction[1] == 1 || roll_direction[1] == 1))
	{
		if (GetPlayer->IsRoll())
		{
			Player->Location[1] -= 1.0f * 700 * Time::Get::Delta();
		}
		else
		{
			Player->Location[1] -= 1.0f * 500 * Time::Get::Delta();
		}
	}
}

void Tilemanager::GenerateMap()
{
	for (int i = 0; i < 400; i++)
	{
		std::vector< Rendering::Tilemap::Component> floor;
		for (int j = 0; j < 400; j++) {
			floor.push_back(Rendering::Tilemap::Component("Dungeon_Tileset",
				{ 32, 32 },
				{ -(1280 * 5) + (j * 32), (1280 * 5) - (i * 32) },
				Rendering::Tilemap::Tile::Empty));
		}
		map.push_back(floor);
	}

	/*for (int i = 180; i < 223; i++)
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
	}*/

	divideDungeon(5, 100, 100, 300, 300);
}

Tilemanager::DungeonLocation Tilemanager::divideDungeon(int depth, int r1, int c1, int r2, int c2)
{
	DungeonLocation Location;

	std::random_device rd;

	std::mt19937 gen(rd());

	std::uniform_int_distribution<int> dis(0, 3);

	if (depth == 0 || (r2 - r1 <= 40 || c2 - c1 <= 20)) {

		for (int i = r1 + 2; i < r2 - 2; i++) {
			for (int j = c1 + 3; j < c2 - 3; j++) {
				if (i == r1 + 2)
				{
					map[i][j].tile = Rendering::Tilemap::Tile::Top_Wall;
				}
				else if (i == r2 - 3)
				{
					map[i][j].tile = Rendering::Tilemap::Tile::Bottom_Wall;
				}
				else 
				{
					map[i][j].tile = Rendering::Tilemap::Tile::Ground;
				}
			}
		}

		for (int i = r1 + 3; i < r2 - 3; i++)
		{
			map[i][c1 + 2].tile = Rendering::Tilemap::Tile::Left_Wall;
			map[i][c2 - 3].tile = Rendering::Tilemap::Tile::Right_Wall;
		}

		return { r1 + 3, c1 + 3, r2 - 4, c2 - 4, r1 + 3, c1 + 3, r2 - 4, c2 - 4 };
	}

	int rLen = r2 - r1;
	int cLen = c2 - c1;
	DungeonLocation temp1, temp2;
	if (rLen / cLen > 1 || (cLen / rLen <= 1 && dis(gen) % 2)) {
		int divideNum = (r2 - r1) * (dis(gen) % 3 + 4) / 10;

		temp1 = divideDungeon(depth - 1, r1, c1, r1 + divideNum, c2);
		temp2 = divideDungeon(depth - 1, r1 + divideNum, c1, r2, c2);

		map[temp1.r4 + 1][(temp1.c3 + temp1.c4) / 2].tile = Rendering::Tilemap::Tile::Ground;
		map[temp1.r4 + 2][(temp1.c3 + temp1.c4) / 2].tile = Rendering::Tilemap::Tile::Ground;
		map[temp1.r4 + 3][(temp1.c3 + temp1.c4) / 2].tile = Rendering::Tilemap::Tile::Ground;
		map[temp1.r4 + 4][(temp1.c3 + temp1.c4) / 2].tile = Rendering::Tilemap::Tile::Ground;

		map[temp1.r4 + 1][(temp1.c3 + temp1.c4) / 2 + 1].tile = Rendering::Tilemap::Tile::Ground;
		map[temp1.r4 + 2][(temp1.c3 + temp1.c4) / 2 + 1].tile = Rendering::Tilemap::Tile::Ground;
		map[temp1.r4 + 3][(temp1.c3 + temp1.c4) / 2 + 1].tile = Rendering::Tilemap::Tile::Ground;
		map[temp1.r4 + 4][(temp1.c3 + temp1.c4) / 2 + 1].tile = Rendering::Tilemap::Tile::Ground;



		map[temp2.r1 - 1][(temp2.c1 + temp2.c2) / 2].tile = Rendering::Tilemap::Tile::Ground;
		map[temp2.r1 - 2][(temp2.c1 + temp2.c2) / 2].tile = Rendering::Tilemap::Tile::Ground;
		map[temp2.r1 - 3][(temp2.c1 + temp2.c2) / 2].tile = Rendering::Tilemap::Tile::Ground;
		map[temp2.r1 - 4][(temp2.c1 + temp2.c2) / 2].tile = Rendering::Tilemap::Tile::Ground;

		map[temp2.r1 - 1][(temp2.c1 + temp2.c2) / 2 + 1].tile = Rendering::Tilemap::Tile::Ground;
		map[temp2.r1 - 2][(temp2.c1 + temp2.c2) / 2 + 1].tile = Rendering::Tilemap::Tile::Ground;
		map[temp2.r1 - 3][(temp2.c1 + temp2.c2) / 2 + 1].tile = Rendering::Tilemap::Tile::Ground;
		map[temp2.r1 - 4][(temp2.c1 + temp2.c2) / 2 + 1].tile = Rendering::Tilemap::Tile::Ground;


		int rmin = min((temp1.c3 + temp1.c4) / 2, (temp2.c1 + temp2.c2) / 2);
		int rmax = max((temp1.c3 + temp1.c4) / 2, (temp2.c1 + temp2.c2) / 2);
		for (int i = rmin; i <= rmax + 1; i++) {
			if (i < rmax)
			{
				map[temp2.r1 - 2][i+2].tile = Rendering::Tilemap::Tile::Bottom_Wall;
				map[temp2.r1 - 5][i].tile = Rendering::Tilemap::Tile::Top_Wall;
			}
			map[temp2.r1 - 3][i].tile = Rendering::Tilemap::Tile::Ground;
			map[temp2.r1 - 4][i].tile = Rendering::Tilemap::Tile::Ground;
		}
	}
	else {
		int divideNum = (c2 - c1) * (rand() % 3 + 4) / 10;

		temp1 = divideDungeon(depth - 1, r1, c1, r2, c1 + divideNum);
		temp2 = divideDungeon(depth - 1, r1, c1 + +divideNum, r2, c2);

		map[(temp1.r3 + temp1.r4) / 2][temp1.c4 + 1].tile = Rendering::Tilemap::Tile::Ground;
		map[(temp1.r3 + temp1.r4) / 2][temp1.c4 + 2].tile = Rendering::Tilemap::Tile::Ground;
		map[(temp1.r3 + temp1.r4) / 2][temp1.c4 + 3].tile = Rendering::Tilemap::Tile::Ground;
		map[(temp1.r3 + temp1.r4) / 2][temp1.c4 + 4].tile = Rendering::Tilemap::Tile::Ground;

		map[(temp1.r3 + temp1.r4) / 2 + 1][temp1.c4 + 1].tile = Rendering::Tilemap::Tile::Ground;
		map[(temp1.r3 + temp1.r4) / 2 + 1][temp1.c4 + 2].tile = Rendering::Tilemap::Tile::Ground;
		map[(temp1.r3 + temp1.r4) / 2 + 1][temp1.c4 + 3].tile = Rendering::Tilemap::Tile::Ground;
		map[(temp1.r3 + temp1.r4) / 2 + 1][temp1.c4 + 4].tile = Rendering::Tilemap::Tile::Ground;



		map[(temp2.r1 + temp2.r2) / 2][temp2.c1 - 1].tile = Rendering::Tilemap::Tile::Ground;
		map[(temp2.r1 + temp2.r2) / 2][temp2.c1 - 2].tile = Rendering::Tilemap::Tile::Ground;
		map[(temp2.r1 + temp2.r2) / 2][temp2.c1 - 3].tile = Rendering::Tilemap::Tile::Ground;
		map[(temp2.r1 + temp2.r2) / 2][temp2.c1 - 4].tile = Rendering::Tilemap::Tile::Ground;

		map[(temp2.r1 + temp2.r2) / 2 + 1][temp2.c1 - 1].tile = Rendering::Tilemap::Tile::Ground;
		map[(temp2.r1 + temp2.r2) / 2 + 1][temp2.c1 - 2].tile = Rendering::Tilemap::Tile::Ground;
		map[(temp2.r1 + temp2.r2) / 2 + 1][temp2.c1 - 3].tile = Rendering::Tilemap::Tile::Ground;
		map[(temp2.r1 + temp2.r2) / 2 + 1][temp2.c1 - 4].tile = Rendering::Tilemap::Tile::Ground;


		int rmin = min((temp1.r3 + temp1.r4) / 2, (temp2.r1 + temp2.r2) / 2);
		int rmax = max((temp1.r3 + temp1.r4) / 2, (temp2.r1 + temp2.r2) / 2);

		for (int i = rmin; i <= rmax; i++) {
			if (i < rmax) 
			{
				map[i + 2][temp2.c1 - 2].tile = Rendering::Tilemap::Tile::Right_Wall;
				map[i][temp2.c1 - 5].tile = Rendering::Tilemap::Tile::Left_Wall;
			}

			map[i][temp2.c1 - 3].tile = Rendering::Tilemap::Tile::Ground;
			map[i][temp2.c1 - 4].tile = Rendering::Tilemap::Tile::Ground;
		}
	}
	Location.r1 = temp1.r1, Location.r2 = temp1.r2, Location.c1 = temp1.c1, Location.c2 = temp1.c2;
	Location.r3 = temp2.r3, Location.r4 = temp2.r4, Location.c3 = temp2.c3, Location.c4 = temp2.c4;

	return Location;
}

void Tilemanager::CreateDungeon()
{
	divideDungeon(4, 0, 0, 400, 400);
}

void Tilemanager::DeInit()
{
	Player = nullptr;
}
