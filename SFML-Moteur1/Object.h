#pragma once
#include "Utilities.h"

class Object
{
	u_int ID;
	string name;

protected:
	bool isUpdated;

public:
	inline string GetObjectName()
	{
		return name;
	}
public:
	Object(string _name);

public :
	virtual void Start() = 0;
	virtual bool Update(float _deltaTime) = 0;
	virtual void Stop() = 0;

};