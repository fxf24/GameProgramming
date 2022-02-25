#pragma once

template <typename T>
class Singleton
{
public :
	static T* GetInstance()
	{
		static T* instance = new T;
		return instance;
	}

	void DeleteSingleton()
	{
		delete GetInstance();
	}
};