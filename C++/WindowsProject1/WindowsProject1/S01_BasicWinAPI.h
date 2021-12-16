#pragma once

// 12:8 로 윈도우를 생성하고
// 격자모양과 키보드 컨트롤로 네모 박스를 옮기는 Class
class S01_BasicWinAPI
{
public :
	void Update();
	void Render();

public :
	POINT player = POINT{ 0,0 };

public :
	S01_BasicWinAPI();
	~S01_BasicWinAPI();
};

