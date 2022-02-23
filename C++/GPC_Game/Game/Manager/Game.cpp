#include "stdafx.h"
#include "Game.h"
#include "Scene/FirstScene.h"

void Game::Start()
{
	Scenes.push_back(new FirstScene);

	Scenes.at(Now)->Start();
}

bool Game::Update()
{
	if (Scenes.at(Now)->Update())
	{
		Scenes.at(Now)->End();

		if (++Now < Scenes.size())
		{
			Scenes.at(Now)->Start();

			return false;
		}
		else { return true; }
	}
	return false;
}

void Game::End()
{
	for (auto scene : Scenes) delete scene;
	player->End();
}

Engine::Game* Engine::Initialize()
{
	return new ::Game();
}