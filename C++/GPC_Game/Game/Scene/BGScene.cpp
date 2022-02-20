#include "stdafx.h"
#include "BGScene.h"

void BGScene::Start()
{
    BG.Content = "background";
    BG.Length = { 1280, 720 };

    BGmusic.Content = "BGM";
    BGmusic.volume = 0.5f;
    BGmusic.Play();
}

bool BGScene::Update()
{
    Camera.Set();
    BG.Draw();

    if (Input::Get::Key::Down(VK_ESCAPE)) return true;

    return false;
}

void BGScene::End()
{
}
