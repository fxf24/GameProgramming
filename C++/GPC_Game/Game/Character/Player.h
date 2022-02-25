#pragma once
#include "Character.h"

#include "Object/Bullet.h"

#include <queue>

class Player : public Character
{
private :
	static Player* Instance;
	Rendering::Animation::Component character;
	Rendering::Camera Cam;
	bool isRoll = false;
	vector<2> roll_direction;
	std::vector<Bullet*> bullet;
	std::queue<Bullet*> pool;

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
};

