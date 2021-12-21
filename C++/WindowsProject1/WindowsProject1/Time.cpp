#include "framework.h"
#include "Time.h"
#include <chrono>
#include <cmath>


Time::Time()
{
	//chrono::system_clock::time_point start = chrono::system_clock::now();
	QueryPerformanceCounter((LARGE_INTEGER*)&m_CurrentTime);		// cpu내의 clock 수
	QueryPerformanceCounter((LARGE_INTEGER*)&m_LastTime);
	QueryPerformanceFrequency((LARGE_INTEGER*)&m_TickPerSecond);	// cpu의 frequency

	m_FPSUpdateInterval = m_TickPerSecond >> 1;	// 10,000,000 --> 1,000,000
}

Time::~Time()
{
	
}

void Time::Update()
{
	// 1. 현재시간을 가져와 시간 간격 및 진행시간을 계산한다.
	QueryPerformanceCounter((LARGE_INTEGER*)&m_CurrentTime);
	timeElapsed = (float)(m_CurrentTime - m_LastTime) / (float)m_TickPerSecond;

	// 2. FPS Update
	m_FrameCount++;

	if (m_CurrentTime - m_LastFPSUpdate > m_FPSUpdateInterval)
	{
		float tmpCurrentTime = (float)m_CurrentTime / (float)m_TickPerSecond;
		float tmpLastTime = (float)m_LastTime / (float)m_TickPerSecond;
		m_FramePerSecond = (float)m_FrameCount / (tmpCurrentTime - tmpLastTime);
		m_LastFPSUpdate = m_CurrentTime;
		m_FrameCount = 0;
	}

	//printf("%f \n", timeElapsed);
	m_LastTime = m_CurrentTime;
	m_RunningTime = m_RunningTime + timeElapsed;

	//printf("%i %i %i\n", m_CurrentTime, m_TickPerSecond, m_FPSUpdateInterval);
}

void Time::Update(float lockFPS)
{
	// 1. 현재시간을 가져와 시간 간격 및 진행시간을 계산한다.
	while (timeElapsed < 1.0f / lockFPS)
	{
		QueryPerformanceCounter((LARGE_INTEGER*)&m_CurrentTime);
		timeElapsed = (float)(m_CurrentTime - m_LastTime) / (float)m_TickPerSecond;
	}

	// 2. FPS Update
	m_FrameCount++;

	if (m_CurrentTime - m_LastFPSUpdate > m_FPSUpdateInterval)
	{
		float tmpCurrentTime = (float)m_CurrentTime / (float)m_TickPerSecond;
		float tmpLastTime = (float)m_LastTime / (float)m_TickPerSecond;
		m_FramePerSecond = (float)m_FrameCount / (tmpCurrentTime - tmpLastTime);
		m_LastFPSUpdate = m_CurrentTime;
		m_FrameCount = 0;
	}

	//printf("%f \n", timeElapsed);
	m_LastTime = m_CurrentTime;
	m_RunningTime = m_RunningTime + timeElapsed;
}
