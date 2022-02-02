#include <Windows.h> // to make Window

namespace Engine
{
	LRESULT CALLBACK Procedure(HWND const, UINT const, WPARAM const, LPARAM const);
}

// APIENTRY : starting point of program
int APIENTRY WinMain
(
	_In_		HINSTANCE const hInstance,
	_In_opt_	HINSTANCE const hprevInstance,
	_In_		LPSTR	  const lpCmdLine,
	_In_		int		  const nShowCmd
)
{
	HWND hWindow = nullptr;

	{
		// base value what class we made
		WNDCLASSEX wndClass		= WNDCLASSEX();

		wndClass.cbSize			= sizeof(WNDCLASSEX);
		// window massege handle function
		wndClass.lpfnWndProc	= Engine::Procedure;
		// who help
		wndClass.hInstance		= hInstance;
		// what Icon
		wndClass.hIcon			= LoadIcon(nullptr, IDI_APPLICATION);
		wndClass.hIconSm		= LoadIcon(nullptr, IDI_APPLICATION);
		wndClass.hCursor		= LoadCursor(nullptr, IDC_ARROW);
		wndClass.hbrBackground	= static_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));
		// set window class name
		wndClass.lpszClassName	= "Window";

		// what descriptor we need
		RegisterClassEx(&wndClass);
	}

	{
		// create window with registered class
		// size of window is 1280, 720 size
		// should be created in center


		CREATESTRUCT window = CREATESTRUCT();

		// get registered class name
		window.lpszClass = "Window";
		// Window name
		window.lpszName = "Game";
		// WS_CAPTION : title bar
		// WS_SYSMENU : show system menu on title bar, can only use when caption is available
		window.style = WS_CAPTION | WS_SYSMENU;
		window.cx = 1280;
		window.cy = 720;
		// who is gonna help to make window
		window.hInstance = hInstance;

		{
			// left right top bottom
			RECT rect = RECT();
			rect.right = window.cx;
			rect.bottom = window.cy;

			// set working area
			AdjustWindowRectEx(&rect, window.style, static_cast<bool>(window.hMenu), window.dwExStyle);
			window.cx = rect.right - rect.left;
			window.cy = rect.bottom - rect.top;

			window.x = (GetSystemMetrics(SM_CXSCREEN) - window.cx) / 2;
			window.y = (GetSystemMetrics(SM_CYSCREEN) - window.cy) / 2;
		}

		hWindow = CreateWindowEx
		(
			window.dwExStyle,
			window.lpszClass,
			window.lpszName ,
			window.style,
			window.x,
			window.y,
			window.cx,
			window.cy,
			window.hwndParent,
			window.hMenu,
			window.hInstance,
			window.lpCreateParams
		);

		ShowWindow(hWindow, SW_RESTORE);
	}

	{
		MSG msg = MSG();

		// GetMessage  : call cycle is fixed, while wait
		// PeekMessage : return  
		// get message and send message
		while (true)
		{
			if (PeekMessage(&msg, HWND(), WM_NULL, WM_NULL, PM_REMOVE))
			{
				if (msg.message == WM_QUIT)
					return static_cast<int>(msg.wParam);

				DispatchMessage(&msg);
			}
			else
			{
				// if there is no message
				// we will send WM_APP
				SendMessage(hWindow, WM_APP, 0, 0);
			}
		}
	}
}
