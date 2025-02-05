#include "ActorTransform.h"

ActorTransform::ActorTransform()
{
	location = Vector2f(0.0f,0.0f);
	scale = Vector2f(1.0f, 1.0f);
	rotation = 0.0f;
}

void ActorTransform::SetLocalLocation(const Vector2f& _location)
{
	location = _location;
}

void ActorTransform::SetScale(const Vector2f& _scale)
{
	scale = _scale;	
}

void ActorTransform::SetRotation(const float _rotation)
{
	rotation = _rotation;
}
