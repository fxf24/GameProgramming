#pragma once
// SceneManager, KeyManager, Mouse 등등은 Singleton으로 구성
//
#define SCENEMANAGER SceneManager::GetInstance()
class SceneManager
{
public :
	static SceneManager* GetInstance()
	{
		static SceneManager singleton;
		return &singleton;
	}
	void Update();
	void Render();

private :
	vector<class Scene*> m_cvScenes;	// 전방선언, Scene을 담아 넣는 곳

private :
	SceneManager();

public :
	~SceneManager();
};

