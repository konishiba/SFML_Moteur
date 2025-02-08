#include "ActorManager.h"

ActorManager::ActorManager()
{
	allActors = set<shared_ptr<Actor>>();
}

void ActorManager::AddActor(shared_ptr<Actor> _actor)
{
	if (allActors.contains(_actor)) return;

	allActors.insert(_actor);
}

void ActorManager::Start()
{
}

void ActorManager::Update()
{
}

void ActorManager::Destroy()
{
}
