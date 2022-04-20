#include "pch.h"
#include "PhysicsObject.h"
#include <iostream>

using namespace sfp;

sfp::PhysicsObject::PhysicsObject(Bounds& bounds,float restitution, float mass):
	bounds(&bounds),restitution(restitution),mass(mass)
{
}

void sfp::PhysicsObject::setPosition(Vector2f center)
{
	bounds->setPosition(center);
}

Vector2f sfp::PhysicsObject::getPosition()
{
	return bounds->getPosition();
}

Bounds& sfp::PhysicsObject::getBounds()
{
	return *bounds;
}

void sfp::PhysicsObject::visualizeBounds(RenderWindow& window)
{
	bounds->visualize(window);
}

float sfp::PhysicsObject::getRestitution()
{
	return restitution;
}

float sfp::PhysicsObject::getMass()
{
	return mass;
}

PhysicsObjectCollisionResult sfp::PhysicsObject::collideWith(
	PhysicsObject& other)
{
	return PhysicsObjectCollisionResult(*this,other,
		this->bounds->collideWith(*other.bounds));
}


