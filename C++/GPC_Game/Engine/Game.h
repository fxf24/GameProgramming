#pragma once
#include "Rendering.h"
#include "Sound.h"
#include "Input.h"

class Game
{
public :
	void BeginPlay();
	void Tick();

private :
	Rendering::Camera Camera;

	Rendering::Image::Component Player;
	Rendering::Image::Component Background;

	Rendering::Animation::Component Amongus;

	Rendering::Text::Component KangFont;

	Sound::Sound Sound;
};

