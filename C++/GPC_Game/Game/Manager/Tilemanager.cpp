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

void Tilemanager::MapGenerate(std::vector< std::vector< Rendering::Tilemap::Component>> map)
{

}

void Tilemanager::DeInit()
{
	Player = nullptr;
}
