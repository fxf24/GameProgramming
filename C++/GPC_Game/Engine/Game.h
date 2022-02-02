#pragma once
#include "Rendering.h"

class Game
{
public :
	void BeginPlay();
	void Tick();

private :
	Rendering::Image::Component Player;
	Rendering::Image::Component Background;

};

