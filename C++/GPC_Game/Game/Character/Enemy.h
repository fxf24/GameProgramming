#pragma once
#include "Character.h"
#include <random>
using namespace Rendering::Animation;

class Enemy : public Character
{
private :
	Component character;
	UINT hp;

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

