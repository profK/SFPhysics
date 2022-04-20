#include "pch.h"
#include "PhysicsRectangleShape.h"

sfp::PhysicsRectangleShape::PhysicsRectangleShape(Vector2f size, PhysicsObject& objectType):
	CenteredRectangle(size),
	PhysicsShape(*this),
	AABB(Vector2f(0,0), size)
{
}
