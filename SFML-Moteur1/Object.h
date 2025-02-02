#pragma once
#include "Utilities.h"

class Object
{
	u_int ID;
	string name;

public:
	inline string GetObjectName()
	{
		return name;
	}
public:
	Object(string _name);

public :
	static void Destroy(shared_ptr<Object> _obj);

};

