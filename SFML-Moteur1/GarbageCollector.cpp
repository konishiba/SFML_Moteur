#include "GarbageCollector.h"

GarbageCollector::GarbageCollector()
{
	objectToDestroy = set<shared_ptr<Object>>();
}

void GarbageCollector::AddToDestroy(shared_ptr<Object> _object)
{
	if (objectToDestroy.contains(_object)) return;

	objectToDestroy.insert(_object);
}

void GarbageCollector::DestroyObjects()
{
	for (shared_ptr<Object> _obj : objectToDestroy)
	{
		cout << _obj.get()->GetObjectName() << " destroyed." << endl;
		_obj.reset();
	}
	cout << "Deleted : " << objectToDestroy.size() << " elements." << endl;
	objectToDestroy.clear();
}
