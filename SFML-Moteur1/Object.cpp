#include "Object.h"
#include "GarbageCollector.h"

Object::Object(string _name)
{
	ID = GetUniqueID();
	name = _name += "_" + to_string(ID);
}