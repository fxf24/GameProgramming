#pragma once
#include "Manager\Scene.h"

class BGScene : public Scene
{
	virtual void Start() override;
	virtual bool Update() override;
	virtual void End() override;

private :
	Rendering::Camera			Camera;
	Rendering::Image::Component BG;

	Sound::Sound				BGmusic;
};

