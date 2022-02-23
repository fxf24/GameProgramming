#pragma once
#include "Character.h"
using namespace Rendering::Animation;

class Player : public Character
{
private :
	static Player* Instance;
	Component character;
	Rendering::Camera Cam;

public :
	virtual void Start() override;
	virtual bool Update() override;
	virtual void End() override;

public :
	static Player* GetInstance()
	{
		if (Instance == nullptr) {
			Instance = new Player();
		}
		return Instance;
	}
	Component GetCharacter()
	{
		return character;
	}
	Rendering::Camera GetCam()
	{
		return Cam;
	}
};

