#pragma once
#include "Manager\Scene.h"
#include "Character/Player.h"
#include "Character/Enemy.h"

class FirstScene : public Scene
{
	virtual void Start() override;
	virtual bool Update() override;
	virtual void End() override;

public :
	Player* player = Player::GetInstance();
	std::vector<Enemy*> enemies;
	Rendering::Image::Component		BG;

	Rendering::Text::Component		Damage;
	
	Rendering::Camera				Cam;

	Sound::Sound					BGmusic;
};

