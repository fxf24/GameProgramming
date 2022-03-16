#pragma once
#include "Singleton.h"

#define GetTilemanager Tilemanager::GetInstance()

class Tilemanager : public Singleton<Tilemanager>
{
private :
	Rendering::Tilemap::Component Tile;
	Rendering::Animation::Component* Player;
	std::vector< std::vector< Rendering::Tilemap::Component>> map;

public :
	typedef struct DungeonLocation{
		int r1, c1, r2, c2;
		int r3, c3, r4, c4;
	}dungeonLocation;

public :
	void Init(Rendering::Tilemap::Component t, Rendering::Animation::Component* pl);

	void TileRange();

	void GenerateMap();

	DungeonLocation divideDungeon(int depth, int r1, int c1, int r2, int c2);
	void CreateDungeon();

	void DeInit();

public :
	std::vector< std::vector< Rendering::Tilemap::Component>> GetMap()
	{
		return map;
	}

};

