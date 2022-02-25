#include "stdafx.h"
#include "SceneManager.h"
#include "Scene/BGScene.h"
#include "Scene/TestScene.h"


SceneManager::SceneManager()
{
	Scenes.try_emplace("BGScene", new BGScene);
	Scenes.try_emplace("TestScene", new TestScene);

	Now = "BGScene";

	Scenes.at(Now)->Start();
}

SceneManager::~SceneManager()
{
	for (auto scene : Scenes) delete scene.second;
}

void SceneManager::ChangeScene(std::string SceneName)
{
	Scenes.at(Now)->End();
	Scenes.at(SceneName)->Start();
	Now = SceneName;
}
