#pragma once
#include "CoreMinimal.h"
#include "Object.h"
#include "ActorTransform.h"
#include "Component.h"

class Actor : public Object
{
	shared_ptr<ActorTransform> transform;
	set<shared_ptr<Component>> components;

	weak_ptr<Actor> parent;
	set<shared_ptr<Actor>> childrens;

protected:
	bool enable;

public:
	inline bool IsEnable() const { return enable; }
	inline shared_ptr<ActorTransform> GetTransform() const { return transform; }
	inline weak_ptr<Actor> GetParent() const { return parent; }
	inline set<shared_ptr<Actor>> GetChildrens() const { return childrens; }

public:
	Actor(shared_ptr<Actor> _parent = nullptr,const string& _name = "Actor");

	//Components
	template<class T>
	shared_ptr<T> GetComponent()
	{
		//for (shared_ptr<Component> _component : components)
		//{
		//	if (T* _cast = dynamic_cast<T*>(_component.get()))
		//	{
		//		return make_shared<T>(_cast);
		//	}
		//}
		return nullptr;
	}

	void AddComponent(shared_ptr<Component> _component);
};

