#pragma once
#include "Engine\Game.h"
#include "Character/Player.h"

class Game final : public Engine::Game
{
public :
	void Start() override;
	bool Update() override;
	void End() override;

public :
	static Rendering::Tilemap::Component* GetTileMap()
	{
		Rendering::Tilemap::Component* map = new Rendering::Tilemap::Component();
		return map;
	}
};

