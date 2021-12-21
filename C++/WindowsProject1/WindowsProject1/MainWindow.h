#pragma once
/// MainWindow Class
/// SingleTone
/// - 단 한번만 클래스가 생성되게 한다.
/// - 방법)
///		1. 생성자를 private로 만든다.
///		2. 함수를 제공하여 생성시키게 한다.
/// 
#define MAIN MainWindow::GetInstance()
class MainWindow
{
public :
	static MainWindow* GetInstance()
	{
		static MainWindow singleTon;
		return &singleTon;
	}

public :
	void Update();			// 키보드 동작에 대한 처리
	void Render();			// Rendering 
	void CreateInstance(HINSTANCE hInstance, int width, int height);
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

public : // Getter
	HWND	GetWindowHandler()	{ return m_hWnd; }
	HDC		GetWindowDC()		{ return m_hDC; }
	int		GetWindowWidth()	{ return m_nWidth; }
	int		GetWindowHeight()	{ return m_nHeight; }

public : // Setter

private : // 내부함수
	void CreateBuffer(); // MemoryDC (화면 깜빡임, 렌더링 속도 빠르게)

private : // 내부변수
	HINSTANCE	m_hInstance = nullptr;	// Program의 handle
	HWND		m_hWnd		= nullptr;	// Window의 handle
	HDC			m_hDC		= nullptr;	// DeviceContext Handle
	HBITMAP		m_hBitmap	= nullptr;	// MemoryDC의 Bitmap
	int			m_nWidth	= 0;	// Window의 Width
	int			m_nHeight	= 0;	// Window의 Height

private :
	MainWindow();  // 생성자

public :
	~MainWindow(); // 소멸자
};

