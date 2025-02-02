#pragma once
#include "Logger.h"
#include "Utilities.h"

#include "TimerManager.h"
#include "GarbageCollector.h"

#define M_TIMER TimerManager::GetInstance()
#define G_COLLECTOR GarbageCollector::GetInstance()
