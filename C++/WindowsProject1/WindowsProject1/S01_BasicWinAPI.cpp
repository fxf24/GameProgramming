#include "framework.h"
#include "S01_BasicWinAPI.h"
#include "Graphic2D.h"
#include "Time.h"

// 생성자
S01_BasicWinAPI::S01_BasicWinAPI()
{
    player.x = 0;
    player.y = 0;


    SetName("S01_BasicWinAPI");
}

S01_BasicWinAPI::~S01_BasicWinAPI()
{
}

// 키보드, 마우스 동작시 플레이어 Update,
// 충돌 테스트

void S01_BasicWinAPI::Update()
{
    POINT pt = player;

    // Mouse
    if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
    {
        POINT mouse;
        GetCursorPos(&mouse);                                   // Screen에서의 마우스 위치 (모니터 화면 상 위치)
        //printf("%d %d\n", mouse.x, mouse.y);

        ScreenToClient(MAIN->GetWindowHandler(), &mouse);       // Screen에서의 위치를 윈도우 위치로 변환
        // 프로그램 창에서의 위치
        //printf("%d %d\n", mouse.x, mouse.y);
        
        // H/W 마우스가 눌러졌을때 Grid안에 정확하게 넣어주는 방법
        int tx = mouse.x % 100;
        int ty = mouse.y % 100;
        mouse.x -= tx;
        mouse.y -= ty;

        pt = mouse;
    }

    if (m_State == eState::Move) // 움직이고 있는 상태
    {
        if (m_Time >= 0.1f)
        {
            m_State = eState::Idle;
            m_Time = 0.0f;
        }
        else
        {
            m_Time += TIMEMANAGER->Delta();
        }
        printf("%f\n", m_Time);
    }
    else
    {
        // 0x8000 : 이전에 누른적이 없고 호출된 시점에서 눌러진 것.
        if (GetAsyncKeyState('A') & 0x8000) 
        {
            m_State = eState::Move;
            pt.x = pt.x - MAIN->GetWindowWidth() / 12;
            m_Time = 0.0f;
        }

        if (GetAsyncKeyState('D') & 0x8000) 
        {
            m_State = eState::Move;
            pt.x = pt.x + MAIN->GetWindowWidth() / 12;
            m_Time = 0.0f;
        }
        if (GetAsyncKeyState('W') & 0x8000) 
        {
            m_State = eState::Move;
            pt.y = pt.y - MAIN->GetWindowHeight() / 8;
            m_Time = 0.0f;
        }
        if (GetAsyncKeyState('S') & 0x8000) 
        {
            m_State = eState::Move;
            pt.y = pt.y + MAIN->GetWindowHeight() / 8;
            m_Time = 0.0f;
        }
    }

    // Check
    if (pt.x < 0) 
    {
        pt.x = 0;
        m_State = eState::Idle;
    }

    if (pt.x >= MAIN->GetWindowWidth())
    {
        pt.x = MAIN->GetWindowWidth() - 100;
        m_State = eState::Idle;
    }

    if (pt.y < 0)
    {
        pt.y = 0;
        m_State = eState::Idle;
    }

    if (pt.y >= MAIN->GetWindowHeight())
    {
        pt.y = MAIN->GetWindowHeight() - 100;
        m_State = eState::Idle;
    }


    player = pt;
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


        // Test
        wstring value = L"FPS :" + to_wstring(TIMEMANAGER->GetFPS());
        Graphic2D::DrawString(MAIN->GetWindowDC(), value, 0, 0, 50, RGB(255, 255, 255));
    }

}


