#pragma once
#include "Scene.h"
// 12:8 로 윈도우를 생성하고
// 격자모양과 키보드 컨트롤로 네모 박스를 옮기는 Class
class S01_BasicWinAPI : public Scene
{
public :
	enum eState
	{
		Idle = 0,
		Move
	};

public :
	virtual void Update() override;
	virtual void Render() override;

private :
	POINT	player	= POINT{ 0,0 };
	eState	m_State = eState::Idle;
	float	m_Time	= 0.0f;

public :
	S01_BasicWinAPI();
	virtual ~S01_BasicWinAPI();
};

