#include "TimerManager.h"

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

	for (shared_ptr<Timer> _timer : allTimers)
	{
		Timer* _temp = _timer.get();
		bool _needToBeDestroyed = _temp->Update(deltaTime);

		if (_needToBeDestroyed)
			_temp->Destroy();
	}
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
