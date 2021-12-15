#include "framework.h"
#include "MainWindow.h"
#include "Resource.h"
#include "Graphic2D.h"

MainWindow::MainWindow()
{
}

MainWindow::~MainWindow()
{
}

void MainWindow::Update()
{
    if (GetAsyncKeyState('A'))
        MessageBox(NULL, L"AAA", L"AAA", MB_OK);
}

void MainWindow::Render()
{
    PAINTSTRUCT ps;

    InvalidateRect(m_hWnd, NULL, true); // 화면을 갱신하라는 메시지

    HDC hdc = BeginPaint(m_hWnd, &ps);
 
    // 격자 모양으로 출력하기  -- 과제

    {
        for (int i = 0; i < 11; i++) {
            Graphic2D::DrawLine(hdc, 10, 10, 500, 500, 2, RGB(255, 0, 0));
        }

        for (int j = 0; j < 7; j++)
        {
            Graphic2D::DrawLine(hdc, 10, 10, 500, 500, 2, RGB(255, 0, 0));
        }
        Graphic2D::DrawLine(hdc, 10, 10, 500, 500, 2, RGB(255, 0, 0));
        Graphic2D::DrawRectangle(hdc, 50, 50, 100, 100, RGB(255, 0, 0));
    }
    

    EndPaint(m_hWnd, &ps);
}

// Window를 Create
// hInstance --> Handle Instance 
// WinAPI   ---> OS (핸들) 
//

void MainWindow::CreateInstance(HINSTANCE hInstance, int width, int height)
{
    // Registry에 등록
    {
        WNDCLASSEXW wcex;

        wcex.cbSize = sizeof(WNDCLASSEX);

        wcex.style = CS_HREDRAW | CS_VREDRAW;
        wcex.lpfnWndProc = WndProc;   // Callback 함수
        wcex.cbClsExtra = 0;
        wcex.cbWndExtra = 0;
        wcex.hInstance = hInstance;
        wcex.hIcon     = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT1));
        wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
        wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
        wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT1);
        wcex.lpszClassName = L"SGA2D";
        wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

        RegisterClassExW(&wcex);
    }

    m_hInstance = hInstance;

//    DWORD dwStyle = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX;
    DWORD dwStyle = WS_OVERLAPPED | WS_SYSMENU ;

    m_hWnd = CreateWindowW(L"SGA2D", L"SGA2D", dwStyle,
        CW_USEDEFAULT, 0, width, height, nullptr, nullptr, hInstance, nullptr);

    //ShowWindow(hWnd, SW_HIDE);
    ShowWindow(m_hWnd, SW_SHOWDEFAULT);
    UpdateWindow(m_hWnd);

}

LRESULT MainWindow::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    /*case WM_KEYDOWN:
        MessageBox(hWnd, L"Key Down", L"Title", MB_OK);
        break;*/
    /*case WM_PAINT:

        break;*/
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}


