#include "Object.h"

Object::Object(string _name)
{
	ID = GetUniqueID();
	name = _name;
}
