#pragma once

class IObjectPoolable abstract
{
private :
	bool CanRecyclable = false;
	bool Visible	   = false;

public :
	virtual ~IObjectPoolable() = default;

	virtual void SetRecycle()
	{
		CanRecyclable = true;
		Visible = false;
	}

	virtual void OnRecycle()
	{
		CanRecyclable = false;
		Visible = true;
	}

	__forceinline bool GetCanRecycle() const
	{
		return CanRecyclable;
	}

	__forceinline bool IsVisible() const
	{
		return Visible;
	}

};
