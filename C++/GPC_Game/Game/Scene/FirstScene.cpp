#include "stdafx.h"
#include "FirstScene.h"
using namespace Rendering::Animation;

void FirstScene::Start()
{
	player->Start();

	Damage.Length = { 500, 200 };
	Damage.Location = { 250 , 100 };
	Damage.Font.Name = "KangWonAll_Bold";
	Damage.Font.Size = 50;
	Damage.Color = { 255, 255, 255 };
	Damage.str = "0";

	BG.Content = "background";
	BG.Length = { 1280 * 3, 720 * 3};

	BGmusic.Content = "BGM";
	BGmusic.volume = 0.5f;
	BGmusic.Play();

	enemies.push_back(new Enemy);
}

bool FirstScene::Update()
{
	BG.Draw();

	player->Update();
	for (auto e : enemies)
	{
		e->Update();
	}

	Damage.Draw();
    return false;
}

void FirstScene::End()
{
	for (auto e : enemies)
	{
		delete e;
	}
}
