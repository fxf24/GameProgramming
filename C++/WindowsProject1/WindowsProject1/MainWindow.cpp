#include "framework.h"
#include "MainWindow.h"
#include "Resource.h"
#include "Graphic2D.h"
#include "S01_BasicWinAPI.h"

S01_BasicWinAPI* m_pScene = nullptr;
MainWindow::MainWindow()
{
    m_pScene = new S01_BasicWinAPI();
}

MainWindow::~MainWindow()
{
    delete m_pScene;
}

void MainWindow::Update()
{
    m_pScene->Update();
}

void MainWindow::Render()
{
    PAINTSTRUCT ps;

    InvalidateRect(m_hWnd, NULL, false); // 화면을 갱신하라는 메시지

    HDC hdc = BeginPaint(m_hWnd, &ps);
    
    // 바탕화면 Render
    Graphic2D::DrawRectangle(GetWindowDC(), -2, -2, GetWindowWidth() + 2, GetWindowHeight() + 4, RGB(2, 2, 27));
    m_pScene->Render();

    // GetWindowDC()의 내용을 고속 복사
    BitBlt(hdc, 0, 0, m_nWidth, m_nHeight, GetWindowDC(), 0, 0, SRCCOPY);

    EndPaint(m_hWnd, &ps);
}

// Window를 Create
// hInstance --> Handle Instance 
// WinAPI   ---> OS (핸들) 
void MainWindow::CreateInstance(HINSTANCE hInstance, int width, int height)
{
    // Registry에 등록
    {
        WNDCLASSEXW wcex;
        m_nWidth = width;
        m_nHeight = height;

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

    DWORD dwStyle = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX;
    //DWORD dwStyle = WS_OVERLAPPED | WS_SYSMENU ;

    m_hWnd = CreateWindowW(L"SGA2D", L"SGA2D", dwStyle,
        CW_USEDEFAULT, 0, width + 16, height + 59, nullptr, nullptr, hInstance, nullptr);

    //ShowWindow(hWnd, SW_HIDE);
    ShowWindow(m_hWnd, SW_SHOWDEFAULT);
    UpdateWindow(m_hWnd);

    // backbuffer 생성
    CreateBuffer();

    RECT rect;

    GetClientRect(m_hWnd, &rect);

 
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

void MainWindow::CreateBuffer()
{
    HDC hdc   = GetDC(m_hWnd);
    m_hDC     = CreateCompatibleDC(hdc);  // 현위도우와 동일구조의 DC를 생성한다.
    m_hBitmap = static_cast<HBITMAP>(CreateCompatibleBitmap(hdc, m_nWidth, m_nHeight));

    SelectObject(m_hDC, m_hBitmap); // Memory DC 사용가능
    ReleaseDC(m_hWnd, hdc);
}


