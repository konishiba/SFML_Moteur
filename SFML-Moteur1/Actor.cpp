#include "Actor.h"
#include "CoreMinimal.h"

Actor::Actor(shared_ptr<Actor> _parent, const string& _name) : Object(_name)
{
	enable = true;

	transform = make_shared<ActorTransform>();
	components = set<shared_ptr<Component>>();

	parent = _parent;
	childrens = set<shared_ptr<Actor>>();
}

void Actor::AddComponent(shared_ptr<Component> _component)
{
	if (components.contains(_component)) return;

	components.insert(_component);
}

void Actor::Start()
{
}

bool Actor::Update(float _deltaTime)
{
	if (!isUpdated) return false;

	return true;
}

void Actor::Stop()
{
}
