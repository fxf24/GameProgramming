#pragma once
#include "Singleton.h"

#define GetCameraManager CameraManager::GetInstance()

class CameraManager final : public Singleton<CameraManager>
{
private :
	Rendering::Image::Component Background;
	Rendering::Animation::Component* Player;
	Rendering::Camera* Camera;

public :
	void Init(Rendering::Image::Component Background, Rendering::Animation::Component* Player, Rendering::Camera* Camera);
	void CamearaRange();
};

