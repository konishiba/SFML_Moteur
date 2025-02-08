#pragma once
#include "CoreMinimal.h"

class ActorTransform
{
	Vector2f localLocation;
	Vector2f scale;
	float rotation;
	
public:
	inline Vector2f GetLocalLocation() const { return localLocation; }
	inline Vector2f GetScale() const { return scale; }
	inline float GetRotation() const { return rotation; }


public:
	ActorTransform();

public:
	void SetLocalLocation(const Vector2f& _location);
	void SetScale(const Vector2f& _scale);
	void SetRotation(const float _rotation);
};

