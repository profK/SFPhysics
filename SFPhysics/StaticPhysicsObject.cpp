#include "pch.h"
#include "StaticPhysicsObject.h"

void sfp::StaticPhysicsObject::applyImpulse(Vector2f impulse)
{
	// does nothing
}

Vector2f sfp::StaticPhysicsObject::getVelocity()
{
	return Vector2f(0,0);
}

void sfp::StaticPhysicsObject::setVelocity(Vector2f v)
{
	//noop because it has no velocity
}
