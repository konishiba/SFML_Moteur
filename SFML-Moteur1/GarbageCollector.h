#pragma once
#include "Singleton.h"
#include "Object.h"

class GarbageCollector : public Singleton<GarbageCollector>
{
	set<shared_ptr<Object>> objectToDestroy;

public:
	GarbageCollector();

public:
	void AddToDestroy(shared_ptr<Object> _object);

	void DestroyGarbages();
};

