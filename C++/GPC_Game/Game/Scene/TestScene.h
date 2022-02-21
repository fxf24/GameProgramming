#pragma once
#include "Manager\Scene.h"

class TestScene : public Scene
{
	virtual void Start() override;
	virtual bool Update() override;
	virtual void End() override;

public :
	Rendering::Animation::Component Player;
	
	Rendering::Image::Component		BG;

	Rendering::Text::Component		Damage;
	
	Rendering::Camera				Cam;

	Sound::Sound					BGmusic;
};

