#pragma once
#include "Logger.h"
#include "Utilities.h"

#include "TimerManager.h"
#include "GarbageCollector.h"
#include "ActorManager.h"

#include "Object.h"

#define M_TIMER TimerManager::GetInstance()
#define G_COLLECTOR GarbageCollector::GetInstance()
#define M_ACTOR ActorManager::GetInstance()

static void DestroyObject(shared_ptr<Object> _obj)
{
	GarbageCollector::GetInstance().AddToDestroy(_obj);
}