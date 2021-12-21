#include "framework.h"
#include "SceneManager.h"
#include "Scene.h"
#include "S01_BasicWinAPI.h"

// 생성자
SceneManager::SceneManager()
{
	m_cvScenes.push_back(new S01_BasicWinAPI());
}

// 소멸자
SceneManager::~SceneManager()
{
	printf("Delete SceneManager\n");

	for (UINT i = 0; i < m_cvScenes.size(); i++)
	{
		delete m_cvScenes[i];
	}

	m_cvScenes.erase(m_cvScenes.begin(), m_cvScenes.end());
	Sleep(1000);
}

// 
void SceneManager::Update()
{
	for (UINT i = 0; i < m_cvScenes.size(); i++) 
	{
		if (m_cvScenes[i]->IsActive())
		{
			m_cvScenes[i]->Update();
		}
	}
}


void SceneManager::Render()
{
	for (UINT i = 0; i < m_cvScenes.size(); i++)
	{
		if (m_cvScenes[i]->IsActive())
		{
			m_cvScenes[i]->Render();
		}
	}
}

