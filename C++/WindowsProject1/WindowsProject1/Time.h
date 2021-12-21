#pragma once
#define TIMEMANAGER Time::GetInstance()

class Time
{
public :
	static Time* GetInstance()
	{
		static Time singleton;
		return &singleton;
	}
	void Update();
	void Update(float lockFPS);		// 일정 시간을 lock하고 업데이트 하겠다.
	float Delta() { return timeElapsed; }
	float GetRunning() { return m_RunningTime; }
	float GetFPS() { return m_FramePerSecond; }

private : // 변수
	float timeElapsed			= 0.0f;		// 현재 경과 시간
	float m_RunningTime			= 0.0f;		// Game에서의 총 run시간
	float m_FramePerSecond		= 0.0f;		// Frame Per Second
	INT64 m_CurrentTime			= 0;		// 현재 시간
	INT64 m_LastTime			= 0;		// 이전시간
	INT64 m_TickPerSecond		= 0;
	INT64 m_FPSUpdateInterval	= 0;		// FPS 간격
	INT64 m_LastFPSUpdate		= 0;		// 마지막 FPS 업데이트 시간
	UINT  m_FrameCount			= 0;		// frame 수

private :
	Time();

public :
	~Time();


};

