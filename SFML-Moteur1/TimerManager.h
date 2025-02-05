#pragma once
#include "Manager.h"
#include "Object.h"

struct Timer : public Object
{
	bool stopped;
	bool activated;
	bool repeat;

	float duration;
	float currentDuration;

	function<void()> callback;

	Timer(const bool _activated, const float _duration, const bool _isRepeated, function<void()> _callback, string _customName) : Object(_customName)
	{
		stopped = true;
		activated = _activated;
		repeat = _isRepeated;

		duration = _duration;
		currentDuration = 0.0f;

		callback = _callback;
	}

	virtual bool Update(float _deltaTime) override
	{
		if (!stopped || !activated) return false;

		currentDuration += _deltaTime;
		if (currentDuration >= duration)
		{
			callback();
			currentDuration = 0.0f;

			return !repeat;
		}

		return false;
	}
};


class TimerManager : public Manager<TimerManager>
{
	// Objet qui contient toutes les données de temps
	Clock clock;
	// Temps depuis le début du programme
	float time;
	// Stocke temporairement la précédente durée de la frame
	float lastTime;
	// Mettre à jour le compteur de FPS
	float lastFrameTime;
	// Temps depuis la dernière image rendue
	float elapsedTime;
	// Temps depuis la dernière image rendue avec le 'timeScale'
	float deltaTime;
	// Vitesse à laquelle le temps s'écoule
	float timeScale;
	// Maximum d'images à rendre par seconde
	u_short maxFrameRate;
	set<shared_ptr<Timer>> allTimers;

public:
	inline string GetCurrentRealTime() const
	{
		const time_t& _now = std::time(0);

		tm _ltm;
		localtime_s(&_ltm, &_now);

		const string& _date = to_string(_ltm.tm_mday) + "/" + to_string(1 + _ltm.tm_mon) + "/" + to_string(1900 + _ltm.tm_year);
		const string& _time = to_string(_ltm.tm_hour) + ":" + to_string(_ltm.tm_min) + ":" + to_string(_ltm.tm_sec);

		return _date + " " + _time;
	}
	inline float GetDeltaTime() const
	{ 
		return deltaTime; 
	}

public:
	TimerManager();

public:
	virtual void Start() override;
	virtual void Update() override;
	virtual void Destroy()  override;

	void UpdateDeltatime();

	shared_ptr<Timer> SetTimer(const bool _activated, const float _duration, const bool _isRepeated, function<void()> _callback, string _customName = "timer");
	void RemoveTimer(shared_ptr<Timer> _timer);
	void Activate(shared_ptr<Timer> _timer);

	void ResumeTimers();
	void StopTimers();

};

