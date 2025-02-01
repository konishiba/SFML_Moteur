#include "Object.h"

Object::Object(string _name)
{
	ID = GetUniqueID();
	name = _name += "_" + to_string(ID);
	destroy = false;
}

void Object::Destroy()
{
	destroy = true;
}
