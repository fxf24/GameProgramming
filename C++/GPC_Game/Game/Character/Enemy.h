#pragma once
#include "Character.h"

using namespace Rendering::Animation;

class Enemy : public Character
{
private :
	Component character;
	UINT hp;
	std::map<int, int> rand;

public :
	virtual void Start() override;
	virtual bool Update() override;
	virtual void End() override;

public :
	Component GetCharacter()
	{
		return character;
	}
};

