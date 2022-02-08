#include "Game.h"

void Game::BeginPlay()
{
	Player.Content	= "Cookie";
	Player.Length	= { 960, 960 };
	Player.Location = { 300, 100 };

	Background.Content	= "background";
	Background.Length	= { 1280, 720 };

	Amongus.Content = "Amongus";
	Amongus.Length = { 1008 / 12.0f, 120 };
	Amongus.Location = { -100, -100 };
	Amongus.Repeatable = true;
	Amongus.Duration = 0.5;
}

void Game::Tick()
{
	Camera.Set();
	Background.Draw();
	Player.Draw();
	Amongus.Draw();
}
