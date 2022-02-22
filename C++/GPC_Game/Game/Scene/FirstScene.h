#pragma once
#include "Manager\Scene.h"
#include "Character/Player.h"

class FirstScene : public Scene
{
	virtual void Start() override;
	virtual bool Update() override;
	virtual void End() override;

public :
	Player* player = Player::GetInstance();
	
	Rendering::Image::Component		BG;

	Rendering::Text::Component		Damage;
	
	Rendering::Camera				Cam;

	Sound::Sound					BGmusic;
};

