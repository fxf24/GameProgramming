#include "framework.h"
#include "S01_BasicWinAPI.h"
#include "Graphic2D.h"

// 생성자
S01_BasicWinAPI::S01_BasicWinAPI()
{
    player.x = 50;
    player.y = 50;
}

S01_BasicWinAPI::~S01_BasicWinAPI()
{
}

void S01_BasicWinAPI::Update()
{
	if (GetAsyncKeyState('A'))
		MessageBox(NULL, L"AAA", L"AAA", MB_OK);
}

void S01_BasicWinAPI::Render()
{
    
    // 격자 모양으로 출력하기
    {
        POINT pt1 = POINT{ 0, 0 };
        POINT pt2 = POINT{ 0, MAIN->GetWindowHeight() };


        for (int i = 0; i < 12; i++) {
            Graphic2D::DrawLine(MAIN->GetWindowDC(), pt1.x, pt1.y, pt2.x, pt2.y, 1, RGB(255, 0, 0));
            pt1.x = pt1.x + (MAIN->GetWindowWidth()) / 12;
            pt2.x = pt1.x;
        }

        pt1 = POINT{ 0,0 };
        pt2 = POINT{ MAIN->GetWindowWidth(), 0 };

        for (int j = 0; j < 8; j++)
        {
            Graphic2D::DrawLine(MAIN->GetWindowDC(), pt1.x, pt1.y, pt2.x, pt2.y, 1, RGB(255, 0, 0));
            pt1.y = pt1.y + (MAIN->GetWindowHeight()) / 8;
            pt2.y = pt1.y;
        }
        
        // Player
        Graphic2D::DrawRectangle(MAIN->GetWindowDC(), player.x, player.y, player.x + 100, player.y + 100, RGB(225, 225, 225));
    }

}


