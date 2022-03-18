#pragma once
#include "Character.h"
#include "Manager/Singleton.h"

#define GetPlayer Player::GetInstance()

class Player : public Character, public Singleton<Player>
{
private :
	Rendering::Animation::Component* character;
	Rendering::Animation::Component gun;
	std::vector < std::string > inventory;
	bool isRoll = false;
	vector<2> roll_direction;
	vector<2> curr_direction;
	int curr_hp = 6;
	int full_hp = 6;
	Collision::RectAngle Hitbox;
	Sound::Sound player_sound;

public :
	virtual void Start() override;
	virtual bool Update() override;
	virtual void End() override;

	Collision::RectAngle GetCharacterHitbox();

public :
	Rendering::Animation::Component* GetCharacter()
	{
		return character;
	}
	vector<2> GetCurrDirection()
	{
		return curr_direction;
	}
	vector<2> GetRollDirection()
	{
		return roll_direction;
	}
	bool IsRoll()
	{
		return isRoll;
	}
};

