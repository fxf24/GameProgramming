#include "stdafx.h"
#include "SceneManager.h"
#include "Scene/FirstScene.h"

SceneManager::SceneManager()
{
	Scenes.try_emplace("FirstScene", new FirstScene);

	Now = "FirstScene";

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