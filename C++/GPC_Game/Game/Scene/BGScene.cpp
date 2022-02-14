#include "stdafx.h"
#include "BGScene.h"

void BGScene::Start()
{
    BG.Content = "Background";
    BG.Length = { 1280, 720 };
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
