#pragma once

class Object abstract
{
	virtual void Start() abstract;
	virtual bool Update() abstract;
	virtual void End() abstract;
};