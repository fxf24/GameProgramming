#pragma once
#include "Character.h"

using namespace Rendering::Animation;

class Enemy : public Character
{
private :
	Component character;
	UINT hp = 5;
	std::map<int, int> rand;
	Collision::RectAngle Hitbox;

public :
	Enemy();

	virtual void Start() override;
	virtual bool Update() override;
	virtual void End() override;

	Collision::RectAngle GetCharacterHitbox();

public :
	Component GetCharacter()
	{
		return character;
	}
	UINT GetEnemyHP()
	{
		return hp;
	}
	void DealEnemyHP(UINT damage)
	{
		hp -= damage;
	}
};

