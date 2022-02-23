#include "TileMap.h"

TileMap::TileMap()
{
	Scale = { 50.0f, 50.0f };

}

TileMap::~TileMap()
{
}

void TileMap::Start()
{
}

void TileMap::Update()
{
}

void TileMap::End()
{
}

void TileMap::Save(std::string file)
{
}

void TileMap::Load(std::string file)
{
}

void TileMap::ResetPosition(vector<2> from, vector<2> to)
{
	for (unsigned i = from[0]; i < to[0]; i++)
	{
		for (unsigned j = from[1]; j < to[0]; j++)
		{

		}
	}
}

void TileMap::ResetTiles(vector<2> from, vector<2> to)
{
}

void TileMap::DeleteTiles(vector<2> from, vector<2> to)
{
}

void TileMap::TileButton()
{
}

void TileMap::TileBrush()
{
}