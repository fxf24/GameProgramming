#pragma once
#include "Util\IObjectPoolable.h"

class Bullet : public IObjectPoolable
{
private :
	UINT damage = 1;

public :
	Bullet();

	void Update();

public :
	void Shoot(vector<2> location, vector<2> direction);
	Collision::Circle GetBulletHitbox();

public :
	vector<2> Direction;
	vector<2> FireLocation;

public :
	Rendering::Image::Component Image;
	Collision::Circle Hitbox;

public :
	UINT GetBulletDamage()
	{
		return damage;
	}
};


