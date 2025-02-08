#include "RootComponent.h"

RootComponent::RootComponent(const Vector2f& _size, const string& _name) : Component(_name)
{
	shape = make_shared<RectangleShape>(_size);
	globalPosition = Vector2f(0.0f, 0.0f);
	movable = true;
}

RootComponent::RootComponent(const float _size, const string& _name) : Component(_name)
{
	shape = make_shared<CircleShape>(_size);
	globalPosition = Vector2f(0.0f, 0.0f);
	movable = true;
}

void RootComponent::Start()
{
}

bool RootComponent::Update(float _deltaTime)
{
	return false;
}

void RootComponent::Stop()
{
}
