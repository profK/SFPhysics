#include "pch.h"
#include "DynamicPhysicsObject.h"

void sfp::DynamicPhysicsObject::applyImpulse(Vector2f impulse)
{
	velocity += impulse;
}

sfp::DynamicPhysicsObject::DynamicPhysicsObject(Bounds& bounds) :
	PhysicsObject(bounds)
{
}

void sfp::DynamicPhysicsObject::update(unsigned int deltaMilliseconds)
{
	Vector2f pos = bounds.getPosition();
	pos += (velocity * (float)deltaMilliseconds);
	bounds.setPosition(pos);
}
