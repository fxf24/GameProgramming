#include "stdafx.h"
#include "Game.h"

void Game::Start()
{
	GetSceneManager;
	for (int i = 0; i < 400; i++)
	{
		GetTileMap()->tileMap.push_back(std::vector< Rendering::Tilemap::Tile>(400));
	}

	/*for (int i = 0; i < 400; i++)
	{
		for (int j = 0; j < 400; j++)
		{
			std::cout << ((GetTileMap()->tileMap[i][j] == Rendering::Tilemap::Tile::Empty)?"Empty":"No")<< " ";
		}
		std::cout << std::endl;
	}*/
}

bool Game::Update()
{
	if (GetSceneManager->GetNowScene()->Update())
	{
		return true;
	}
	return false;
}

void Game::End()
{
	GetSceneManager->DeleteSingleton();
	GetPlayer->DeleteSingleton();
}

Engine::Game* Engine::Initialize()
{
	return new ::Game();
}