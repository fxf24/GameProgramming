#pragma once

class Character abstract
{
public :
	virtual void Start() abstract;
	virtual bool Update() abstract;
	virtual void End() abstract;

	template <typename T>
	T GetCharacterHitbox();
};