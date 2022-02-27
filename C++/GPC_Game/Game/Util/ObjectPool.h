#pragma once
#include <vector>

#include "IObjectPoolable.h"

class ObjectPool
{
public:
    std::vector<IObjectPoolable*> PoolObjects;

public:
    template<typename T>
    T* GetRecycledObject()
    {
        T* poolObj = nullptr;

        if (PoolObjects.size() == 0)
        {
            PoolObjects.push_back(dynamic_cast<IObjectPoolable*>(poolObj = new T));
            return poolObj;
        }

        for (auto elem : PoolObjects)
        {
            if (elem->CanRecylcable)
            {
                poolObj = static_cast<T*>(elem);
                break;
            }
        }

        if (poolObj == nullptr)
        {
            PoolObjects.push_back(dynamic_cast<IObjectPoolable*>(poolObj = new T));
            return poolObj;
        }

        poolObj->OnRecycle();

        return poolObj;
    }
};
