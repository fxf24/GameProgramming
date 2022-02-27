#pragma once
#include "Character.h"

class Player : public Character
{
private :
	static Player* Instance;
	Rendering::Animation::Component character;
	Rendering::Camera Cam;
	bool isRoll = false;
	vector<2> roll_direction;

public :
	virtual void Start() override;
	virtual bool Update() override;
	virtual void End() override;

public :
	static Player* GetInstance()
	{
		return new Player();
	}
	Rendering::Animation::Component GetCharacter()
	{
		return character;
	}
	Rendering::Camera GetCam()
	{
		return Cam;
	}
	bool IsRoll()
	{
		return isRoll;
	}
};

