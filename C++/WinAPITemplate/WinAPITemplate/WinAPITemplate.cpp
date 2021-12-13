#include <Windows.h>
//#include "WinAPITemplate.h"

/* 
    WIN API
    WIN : Window OS
    API : Application Programming Interface (Function)

    <Windows.h> 추가 시켜야합니다.
    윈도우에서 제공하는 함수들의 소스코드들이 들어있습니다.
*/

#define MAX_LOADSTRING 100 // 매크로 상수 : 문자열 로드의 최대 길이

HINSTANCE hInst;
/*
    HINSTANCE : 인스턴스 핸들 (INSTANCE HANDLE)
    Instance  : 어떠한 자료형을 기준으로 생성한 후의 사용하고 있는 객체
    Handle    : 프로세서들의 위치를 나타내고 있는 주소
    Processor : 현재 실행되고 있는 프로그램을 의미합니다.

*/
wchar_t szTitle[MAX_LOADSTRING] = L"API Game";                 // 창의 타이틀 이름입니다.
// char  = 1 Byte
// wchar = 2 Byte
// 상수 표기할 때
// 100    == int       100.0  == double             100.0f == float
// 'A'    == char      "A"    == const char*
// L'A'   == wchar_t   L"A"   == const wchar_t*
//
wchar_t szWindowClass[MAX_LOADSTRING] = L"Window";             // 창 클래스의 이름입니다.

// API 에서 사용할 함수들을 선언하고 있는 부분입니다.
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);

// wWinMain : 창 프로그램의 시작 위치를 나타냅니다.
// main     : 콘솔 프로그램의 시작 위치를 나타냅니다.
// APIENTRY : API의 진입점을 나타냅니다.
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    MyRegisterClass(hInstance);

    // 창이 생성되지 않았다면
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE; // 프로그램을 종료시킵니다.
    }

    MSG msg; // 메시지를 저장할 구조체
 
    // GetMessage : 메세지를 읽어옵니다.
    // WM_QUIT 메세지를 읽는다면 false를 반환합니다.
    // GetMessage 는 만약 메세지가 없다면 대기타입을 가집니다.
    // 대기타임 : 반복문을 잠재웁니다.
    // 메세지가 들어온다면 true를 반환합니다.
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        // DispatchMessage : 읽어들인 메세지를 WndProc 함수로 이동시킵니다.
        DispatchMessage(&msg);
    }

    return (int) msg.wParam; // 프로그램을 종료시킵니다.
}

// 창 클래스를 등록하는 함수입니다.
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    // WNDCLASSEXW : 창 클래스를 등록하기 전 요청서를 작성하는 구조체입니다.
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX); // 클래스의 크기

    wcex.style          = CS_HREDRAW | CS_VREDRAW;                           // 윈도우 스타일
                       // CS_HREDRAW | CS_VREDRAW : 너비와 높이가 변경될 때 다시 그리도록 설정.
    wcex.lpfnWndProc    = WndProc;                                           // 메시지 처리 함수
    wcex.cbClsExtra     = 0;                                                 // 클래스의 여분 메모리
    wcex.cbWndExtra     = 0;                                                 // 윈도우의 여분 메모리
    wcex.hInstance      = hInstance;                                         // 인스턴스 핸들
    wcex.hIcon          = LoadIcon(nullptr, IDI_APPLICATION);                // 큰 아이콘
    // LoadIcon(hInstance, Icon) : hInstance 에 있는 Icon을 로드해주는 함수입니다.
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);                    // 마우스 커서
    // LoadCursor(hInstance, Cursor) : hInstance 에 있는 Cursor를 로드해주는 함수 
    wcex.hbrBackground  = static_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));  // 배경
    // HBRUSH         : 색상을 나타내는 구조체입니다.
    // GetStockObject : 윈도우에서 제공하는 자원을 가져와 주는 함수입니다.
    wcex.lpszMenuName   = nullptr;                                           // 메뉴
    wcex.lpszClassName  = szWindowClass;                                     // 클래스이름
    wcex.hIconSm        = LoadIcon(nullptr, IDI_APPLICATION);                // 작은 아이콘

    return RegisterClassExW(&wcex); 
    // RegisterClassExW() : 만든 요청서의 토대로 컴퓨터에게 창 클래스를 등록하라고 하는 함수입니다
}

// InitInstance : 등록한 클래스로 객체를 만들고 초기화하는 함수
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; 

   // HWND (Window Handle) : 창이 실행되고 있는 위치
   HWND hWnd = 
       // CreateWindowW : 등록한 클래스로 창을 만들고 생성한 창의 위치를 반환합니다.
       CreateWindowW(
           szWindowClass,           // 창 클래스 이름
           szTitle,                 // 창 타이틀 이름
           WS_OVERLAPPEDWINDOW,     // 윈도우 스타일
           // WS_OVERLAPPEDWINDOW : 기본 위도우 스타일을 사용하겠다.
           0,                       // 창의 생성 위치 x 
           0,                       //               y
           500,                     // 창의 너비 크기
           500,                     // 창의 높이 크기
           nullptr,                 // 부모 윈도우 핸들
           nullptr,                 // 메뉴 핸들
           hInstance,               // 인스턴스 핸들
           nullptr);                // Create 메시지에 보내는 값

   // 0 : false
   // 0 이 아닌값 : true
   // hWnd 가 nullptr 라면 
   if (!hWnd)
   {
      return FALSE; // 프로그램을 종료합니다.
   }

   // ShowWindow : 창을 보여주는 함수입니다.
   ShowWindow(hWnd, nCmdShow);
   // nCmdShow : 창을 어떻게 보여줄지 정해주는 부분 ex) SW_HIDE, SW_MINIMIZE 등

   return TRUE;
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

