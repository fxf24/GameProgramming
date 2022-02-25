#pragma once
#include "Object.h"

class Bullet : public Object
{
private :
	UINT damage;
	vector<2> bullet_direction;
	float speed;

	Rendering::Image::Component image;

public :
	virtual void Start() override;
	virtual bool Update() override;
	virtual void End() override;

public :
	void SetBulletDirection(vector<2> bd)
	{
		bullet_direction = bd;
	}
	vector<2> GetBulletDirection() 
	{
		return bullet_direction;
	}

	Rendering::Image::Component GetComponent() {
		return image;
	}
	void SetLocation(vector<2> l)
	{
		image.Location = l;
	}
};

