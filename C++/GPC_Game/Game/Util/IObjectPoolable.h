#pragma once

class IObjectPoolable
{
public:
	bool CanRecylcable = false;

public:
	virtual ~IObjectPoolable() = default;

	virtual void SetRecycle()
	{
		CanRecylcable = true;
	}

	virtual void OnRecycle()
	{
		CanRecylcable = false;
	}

	virtual void Update()
	{
		if (CanRecylcable) return;
	}
};