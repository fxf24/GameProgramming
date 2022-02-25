#include "stdafx.h"
#include "Bullet.h"

void Bullet::Start()
{
	image.Content = "bullet";
	image.Length = { 12, 12 };

	speed = 1000.0f;
}

bool Bullet::Update()
{
	if (length(bullet_direction) != 0)
	{
		image.Location += bullet_direction * speed * Time::Get::Delta();
	}

	image.Draw();
	return false;
}

void Bullet::End()
{

}
