#include "TimerManager.h"
#include "CoreMinimal.h"

TimerManager::TimerManager()
{
	clock = Clock();
	time = 0.0f;
	lastTime = 0.0f;
	lastFrameTime = 0.0f;
	elapsedTime = 0.0f;
	deltaTime = 0.0f;
	timeScale = 1.0f;
	maxFrameRate = 60;
	allTimers = set<shared_ptr<Timer>>();
}

void TimerManager::Start()
{

}

void TimerManager::Update()
{
	if (!isUpdated) return;

	UpdateDeltatime();

	set<shared_ptr<Timer>> _timerToDelete = set<shared_ptr<Timer>>();

	// Update of Timers
	for (shared_ptr<Timer> _timer : allTimers)
	{
		Timer* _temp = _timer.get();
		bool _needToBeDestroyed = _temp->Update(deltaTime);

		if (_needToBeDestroyed)
		{
			_timerToDelete.insert(_timer);
			G_COLLECTOR.AddToDestroy(_timer);
		}
	}

	// Delete Timers in the list if needed
	for (shared_ptr<Timer> _timer : _timerToDelete)
	{
		RemoveTimer(_timer);
	}
	_timerToDelete.clear();
}

void TimerManager::Destroy()
{

}

void TimerManager::UpdateDeltatime()
{
	lastTime = time;
	time = clock.getElapsedTime().asSeconds();
	elapsedTime = time - lastTime;
	deltaTime = elapsedTime * timeScale;

}

shared_ptr<Timer> TimerManager::SetTimer(const bool _activated, const float _duration, const bool _isRepeated, function<void()> _callback, string _customName)
{
	shared_ptr<Timer> _timer = make_shared<Timer>(_activated, _duration, _isRepeated, _callback,_customName);
	allTimers.insert(_timer);

	return _timer;
}

void TimerManager::RemoveTimer(shared_ptr<Timer> _timer)
{
	if (!allTimers.contains(_timer)) return;

	allTimers.erase(_timer);
}

void TimerManager::Activate(shared_ptr<Timer> _timer)
{
	if (!allTimers.contains(_timer)) return;

	set<shared_ptr<Timer>>::iterator _it = allTimers.find(_timer);
	_it->get()->activated = true;
}

void TimerManager::ResumeTimers()
{
	for (shared_ptr<Timer> _timer : allTimers)
	{
		_timer.get()->stopped = false;
	}
}

void TimerManager::StopTimers()
{
	for (shared_ptr<Timer> _timer : allTimers)
	{
		_timer.get()->stopped = true;
	}
}
