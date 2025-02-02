#include "GarbageCollector.h"
#include "CoreMinimal.h"

GarbageCollector::GarbageCollector()
{
	objectToDestroy = set<shared_ptr<Object>>();
}

void GarbageCollector::AddToDestroy(shared_ptr<Object> _object)
{
	if (objectToDestroy.contains(_object)) return;

	objectToDestroy.insert(_object);
}

void GarbageCollector::DestroyGarbages()
{
	for (shared_ptr<Object> _obj : objectToDestroy)
	{
		// _obj.use_count() - 2 => 2 others ref is _obj and in objectToDestroy
		cout << _obj.get()->GetObjectName() << " destroyed. " << "Miss " << (_obj.use_count() - 2) << " other ref." << endl;
		_obj.reset();
	}
	cout << "Deleted : " << objectToDestroy.size() << " elements." << endl;
	objectToDestroy.clear();

}
