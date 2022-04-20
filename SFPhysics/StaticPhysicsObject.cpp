#include "pch.h"
#include "StaticPhysicsObject.h"

sfp::StaticPhysicsObject::StaticPhysicsObject(Bounds& bounds):
	PhysicsObject(bounds)
{
}

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

void sfp::StaticPhysicsObject::update(unsigned int deltaMillisconds)
{
	//nop
}

float sfp::StaticPhysicsObject::getMass()
{
	return std::numeric_limits<float>::max();
}
