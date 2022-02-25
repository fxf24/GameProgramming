#include "stdafx.h"
#include "Game.h"
#include "Scene/BGScene.h"
#include "Scene/TestScene.h"


void Game::Start()
{
	SceneManager::GetInstance();
}

bool Game::Update()
{
	if (SceneManager::GetInstance()->GetNowScene()->Update())
	{
		return true;
	}
	return false;
}

void Game::End()
{
	SceneManager::GetInstance()->DeleteSingleton();
}

Engine::Game* Engine::Initialize()
{
	return new ::Game();
}