#pragma once
#include "Singleton.h"

#define GetTilemanager Tilemanager::GetInstance()

class Tilemanager : public Singleton<Tilemanager>
{
private :
	Rendering::Tilemap::Component Tile;
	Rendering::Animation::Component* Player;

public :
	void Init(Rendering::Tilemap::Component t, Rendering::Animation::Component* pl);

	void TileRange();

	void MapGenerate(std::vector< std::vector< Rendering::Tilemap::Component>> map);

	void DeInit();
};

