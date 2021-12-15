#pragma once
/// MainWindow Class
/// 
/// 
class MainWindow
{
public :
	void Update();			// 키보드 동작에 대한 처리
	void Render();			// Rendering 
	void CreateInstance(HINSTANCE hInstance, int width, int height);
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

public : // Getter
	HWND GetWindowHandler() { return m_hWnd; }

public : // Setter


private : // 내부변수, 내부함수
	HINSTANCE m_hInstance = nullptr;
	HWND m_hWnd = nullptr;

public  : // 생성자, 소멸자 
	MainWindow();  // 생성자
	~MainWindow(); // 소멸자
};

