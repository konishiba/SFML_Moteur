#pragma once
#include "Component.h"

class RootComponent : public Component
{
	shared_ptr<Shape> shape;
	Vector2f globalPosition;
	bool movable;

public:
	inline shared_ptr<Shape> GetShape() const { return shape; }

public:
	//Create a RectangleShape
	RootComponent(const Vector2f& _size,const string& _name = "RootComponent");
	//Create a CircleShape
	RootComponent(const float _size,const string& _name = "RootComponent");

public:
	virtual void Start() override;
	virtual bool Update(float _deltaTime) override;
	virtual void Stop() override;
};

