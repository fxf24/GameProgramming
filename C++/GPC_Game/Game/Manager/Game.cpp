#include "stdafx.h"
#include "Game.h"
#include "Scene/TestScene.h"


void Game::Start()
{
	//Scenes.push_back(new BGScene);
	Scenes.push_back(new TestScene);

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
}

Engine::Game* Engine::Initialize()
{
	return new ::Game();
}