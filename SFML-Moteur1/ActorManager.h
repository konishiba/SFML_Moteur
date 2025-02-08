#pragma once
#include "Utilities.h"
#include "Manager.h"

class Actor;

class ActorManager : public Manager<ActorManager>
{
	set<shared_ptr<Actor>> allActors;

public:
	inline set<shared_ptr<Actor>> GetAllActors() const { return allActors; }

public:
	ActorManager();

public:
	void AddActor(shared_ptr<Actor> _actor);
	
	virtual void Start() override;
	virtual void Update() override;
	virtual void Destroy() override;
};

