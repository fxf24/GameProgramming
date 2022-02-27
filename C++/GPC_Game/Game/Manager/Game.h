#pragma once
#include "Engine\Game.h"
#include "Character/Player.h"

class Game final : public Engine::Game
{
public :
	void Start() override;
	bool Update() override;
	void End() override;
};

