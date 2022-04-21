#include "pch.h"
#include "PhysicsRectangle.h"

sfp::PhysicsRectangle::PhysicsRectangle(Vector2f center, Vector2f size, bool isStatic):
	CenteredRectangle(size),AABB(center-(size/2.0f),center+(size/2.0f)),
	PhysicsBody(*this,isStatic)
{
	setCenter(center);
}
