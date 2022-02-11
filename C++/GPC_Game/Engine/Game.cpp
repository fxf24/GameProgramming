#include "Game.h"
#include "Time/Time.h"
#include <Windows.h>

void Game::BeginPlay()
{
	Player.Content	= "Cookie";
	Player.Length	= { 960, 960 };
	Player.Location = { 300, 100 };

	Background.Content	= "background";
	Background.Length	= { 1280 * 3, 720 * 3};

	Amongus.Content = "Amongus";
	Amongus.Length = { 1008 / 12.0f, 120 };
	Amongus.Location = { -100, -100 };
	Amongus.Repeatable = true;
	Amongus.Duration = 0.5;

	Sound.Content = "BGM";
	Sound.volume = 0.1f;
	Sound.Play();

	KangFont.Length    = { 500, 200 };
	KangFont.Location  = { 250, 100 };
	KangFont.Font.Name = "KangWonAll_Bold";
	KangFont.Font.Size = 50;
	KangFont.Color     = { 255, 255, 255 };
	KangFont.str	   = "Korean";
}

void Game::Tick()
{
	if (Input::Get::Key::Press(0x31)) Sound.Play();
	if (Input::Get::Key::Press(0x32)) Sound.Pause();
	if (Input::Get::Key::Press(0x33)) Sound.Stop();
	
	vector<2> direction;

	if (Input::Get::Key::Press(VK_LEFT))
	{
		Amongus.direction = true;
		direction[0] -= 1;
	}
	if (Input::Get::Key::Press(VK_RIGHT))
	{
		Amongus.direction = false;
		direction[0] += 1;
	}
	if (Input::Get::Key::Press(VK_UP))		direction[1] += 1;
	if (Input::Get::Key::Press(VK_DOWN))	direction[1] -= 1;

	if (length(direction) != 0)
	{
		Camera.Location += normalize(direction) * 500 * Time::Get::Delta();
		Amongus.Location += normalize(direction) * 500 * Time::Get::Delta();
	}
	
	Camera.Set();
	Background.Draw();
	Player.Draw();
	Amongus.Draw();
	KangFont.Draw();
}
