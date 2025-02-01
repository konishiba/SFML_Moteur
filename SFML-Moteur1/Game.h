#pragma once
#include "CoreMinimal.h"

class Game
{
protected:
	RenderWindow window;

public:
	inline bool IsOver() const
	{
		return !window.isOpen();
	}
	inline Vector2f GetWindowSize() const
	{
		return static_cast<Vector2f>(window.getSize());
	}

public:
	Game();

public:
	virtual void Start();
	virtual bool Update();
	void UpdateWindow();
	virtual void Stop();
};