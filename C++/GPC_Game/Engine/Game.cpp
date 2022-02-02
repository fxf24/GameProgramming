#include "Game.h"

void Game::BeginPlay()
{
	Player.Content	= "Cookie";
	Player.Length	= { 960, 960 };
	Player.Location = { 300, 100 };

	Background.Content	= "background";
	Background.Length	= { 1280, 720 };
}

void Game::Tick()
{
	Background.Draw();
	Player.Draw();
}
