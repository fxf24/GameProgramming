#pragma once
#include "Manager\Scene.h"

class TestScene : public Scene
{
	virtual void Start() override;
	virtual bool Update() override;
	virtual void End() override;

public :
	Rendering::Animation::Component Player;
	Rendering::Animation::Component monster;

	Rendering::Text::Component		Damage;
	
	Rendering::Camera Cam;
};

