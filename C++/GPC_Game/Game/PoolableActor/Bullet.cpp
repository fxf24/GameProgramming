#include "stdafx.h"
#include "Bullet.h"

Bullet::Bullet()
{
	Image.Content = "bullet";
	Image.Length = { 20, 20 };
}

void Bullet::Update()
{
	IObjectPoolable::Update();
	Image.Location += normalize(Direction) * 1000 * Time::Get::Delta();

	if (length(FireLocation - Image.Location) > 1000.0f)
		SetRecycle();

	Image.Draw();
}

void Bullet::Shoot(vector<2> location, vector<2> direction)
{
	Image.Location = FireLocation = location;
	Direction = direction;
}

