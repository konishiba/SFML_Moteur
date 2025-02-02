#include "Object.h"
#include "GarbageCollector.h"

Object::Object(string _name)
{
	ID = GetUniqueID();
	name = _name += "_" + to_string(ID);
}

void Object::Destroy(shared_ptr<Object> _obj)
{
	GarbageCollector::GetInstance().AddToDestroy(_obj);
}
