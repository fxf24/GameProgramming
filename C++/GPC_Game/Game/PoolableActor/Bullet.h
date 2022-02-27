#pragma once
#include "Util\IObjectPoolable.h"

class Bullet : public IObjectPoolable
{
public:
	Bullet();

	void Update();

public:
	void Shoot(vector<2> location, vector<2> direction);

public:
	vector<2> Direction;
	vector<2> FireLocation;

public:
	Rendering::Image::Component Image;
};


