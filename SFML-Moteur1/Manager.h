#pragma once
#include "Singleton.h"

template<class T>
class Manager : public Singleton<T>
{
protected:
	bool isUpdated = true;

public:
	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void Destroy() = 0;
};

