#pragma once
#include "Manager\Scene.h"
#include "Character/Player.h"
#include "Character/Enemy.h"
#include "Util/ObjectPool.h"
#include "PoolableActor/Bullet.h"

class FirstScene : public Scene
{
	virtual void Start() override;
	virtual bool Update() override;
	virtual void End() override;

private :
	ObjectPool* BulletPooling;
	std::vector<Enemy*> enemies;

	Rendering::Text::Component		Damage;
	
	Rendering::Camera*				Camera;

	Sound::Sound					BGmusic;
	Sound::Sound					bullet_sound;

	std::vector< std::vector< Rendering::Tilemap::Component>> map;
};

