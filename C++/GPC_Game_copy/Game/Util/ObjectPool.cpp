#include "stdafx.h"
#include "ObjectPool.h"

IObjectPoolable* ObjectPool::GetRecycledObject() const
{
	if (PoolObjects.size() == 0) return nullptr;
	
	IObjectPoolable* poolObj = nullptr;

	for (auto elem : PoolObjects)
	{
		if (elem->GetCanRecycle())
		{
			poolObj = elem;
			break;
		}
	}

	if (poolObj == nullptr)
		return nullptr;

	poolObj->OnRecycle();

	return poolObj;
}
