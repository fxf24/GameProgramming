#pragma once
// 추상클래스
// - virtual 함수가 하나라도 있으면 추상화 class 라고 한다.
// - 객체를 생성할 수 없다.
// - 왜 추상 클래스를 사용하는 가? 표준, 여러 멤버, 놓치는 함수(역할) 구조적으로 할 수 있게 끔

class Scene
{
public :
	virtual void Update() = 0; // 상속 받은 클래스에서 반드시 구현을 해줘라
	virtual void Render() = 0; // 상속 받은 클래스에서 반드시 구현을 해줘라

	//Getter()
	string	GetName()	{ return m_strSceneName; }
	bool	IsActive()	{ return m_bActive; }

	//Setter()
	void	SetName(string strName) { m_strSceneName = strName; }
	void	SetActive(bool active)		{ m_bActive = active; }

private :	// 자기자신만 수정

protected :	// 상속받은 클래스도 수정 가능
	string	m_strSceneName;		// 현재 Scene의 명칭
	bool	m_bActive = true;	// 현재 Scene이 활성화

public :
//	Scene()  {};
//	virtual ~Scene() {};
};

