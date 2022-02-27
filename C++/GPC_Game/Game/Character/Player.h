#pragma once
#include "Character.h"
#include "Manager/Singleton.h"

#define GetPlayer Player::GetInstance()

class Player : public Character, public Singleton<Player>
{
private :
	Rendering::Animation::Component character;
	Rendering::Camera Cam;
	bool isRoll = false;
	vector<2> roll_direction;
	int hp;

public :
	virtual void Start() override;
	virtual bool Update() override;
	virtual void End() override;

public :
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

