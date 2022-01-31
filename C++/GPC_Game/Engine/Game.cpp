#include "Game.h"

void Game::BeginPlay()
{
	Player.Content  = "Cookie";
	Player.Length   = { 300 , 300 };
	Player.Location = { 300 , 200 };

	Background.Content = "background";
	Background.Length  = { 1280, 720 };
}

void Game::Tick()
{
	Background.Draw();
	Player.Draw();
}
