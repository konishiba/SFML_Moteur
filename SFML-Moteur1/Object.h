#pragma once
#include "Utilities.h"

class Object
{
	u_int ID;
	string name;
	bool destroy;

public:
	Object(string _name);

public :
	void Destroy();

};

