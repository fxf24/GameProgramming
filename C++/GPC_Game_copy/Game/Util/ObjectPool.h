#pragma once
#include "IObjectPoolable.h"

class ObjectPool
{
public :
	std::vector<IObjectPoolable*> PoolObjects;

public :
	template <typename T>
	T* RegisterObject(T* newObject)
	{
		PoolObjects.push_back(dynamic_cast<IObjectPoolable*>(newObject));
		return newObject;
	}

	IObjectPoolable* GetRecycledObject() const;
};

