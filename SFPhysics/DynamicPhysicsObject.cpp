#include "pch.h"
#include "DynamicPhysicsObject.h"

void sfp::DynamicPhysicsObject::applyImpulse(Vector2f impulse)
{
	velocity += impulse;
}

sfp::DynamicPhysicsObject::DynamicPhysicsObject(Bounds& bounds,
	float restitution,float mass) :
	PhysicsObject(bounds,restitution,mass)
{
}

void sfp::DynamicPhysicsObject::update(unsigned int deltaMilliseconds)
{
	Vector2f pos = bounds.getPosition();
	pos += (velocity * (float)deltaMilliseconds);
	bounds.setPosition(pos);
}

Vector2f sfp::DynamicPhysicsObject::getVelocity()
{
	return velocity;
}

void sfp::DynamicPhysicsObject::setVelocity(Vector2f v)
{
	velocity = v;
}
