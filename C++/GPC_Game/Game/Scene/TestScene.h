#pragma once
#include "Manager/Scene.h"

class TestScene : public Scene
{
	// Scene을(를) 통해 상속됨
	virtual void Start() override;
	virtual bool Update() override;
	virtual void End() override;
};

