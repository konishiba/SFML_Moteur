#pragma once
#include "CoreMinimal.h"
#include "Object.h"

class Actor;

class Component : public Object
{
	weak_ptr<Actor> owner;

public:
	Component(const string& _name);

public:
	virtual void Start() override;
	virtual bool Update(float _deltaTime) override;
	virtual void Stop() override;
};

