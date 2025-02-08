#include "Component.h"

Component::Component(const string& _name) : Object(_name)
{
}

void Component::Start()
{
}

bool Component::Update(float _deltaTime)
{
	return false;
}

void Component::Stop()
{
}
