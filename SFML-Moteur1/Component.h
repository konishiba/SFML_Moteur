#pragma once
#include "CoreMinimal.h"
#include "Object.h"

class Actor;

class Component : public Object
{
	weak_ptr<Actor> owner;

public:
	Component(const string& _name) : Object(_name)
	{

	}
	virtual void Update() = 0;
};

