#include "framework.h"
#include "Time.h"
#include <chrono>

Time::Time()
{
	start = chrono::system_clock::now();
}

Time::~Time()
{
	
}

void Time::Update()
{
	// 1. 현재시간을 가져와 시간 간격 및 진행시간을 계산한다.
	chrono::duration<double> sec = chrono::system_clock::now() - start;

	m_TimeElepased = (float)sec.count();
	start = std::chrono::system_clock::now();

	// 2. FPS Update
	m_FrameCount++;
	m_RunningTime = m_RunningTime + m_TimeElepased;

	m_FPStimeElepased = m_FPStimeElepased + m_TimeElepased;

	if (m_FPStimeElepased > 1.0f)
	{
		m_FramePerSecond = m_FrameCount / m_FPStimeElepased;
		m_FrameCountPerSecond = m_FrameCount;
		m_FPStimeElepased = 0.0f;
		m_FrameCount = 0;
	}
}

void Time::Update(float lockFPS)
{
	// 1. 현재시간을 가져와 시간 간격 및 진행시간을 계산한다.
	std::chrono::duration<double> sec = std::chrono::system_clock::now() - start;

	m_TimeElepased = (float)sec.count();
	while (m_TimeElepased < 1.0f / lockFPS)
	{
		sec = std::chrono::system_clock::now() - start;
		m_TimeElepased = (float)sec.count();

	}

	// 2. FPS Update
	start = std::chrono::system_clock::now();
	m_FrameCount++;
	m_RunningTime = m_RunningTime + m_TimeElepased;

	m_FPStimeElepased = m_FPStimeElepased + m_TimeElepased;

	if (m_FPStimeElepased > 1.0f)
	{
		m_FramePerSecond = m_FrameCount / m_FPStimeElepased;
		m_FrameCountPerSecond = m_FrameCount;
		m_FPStimeElepased = 0.0f;
		m_FrameCount = 0;
	}
}

void Time::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_TIMER:
		MessageBox(hWnd, L"Timer", L"Title", MB_OK);
		break;
	}
}