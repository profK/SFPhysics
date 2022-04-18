#include "pch.h"
#include "PhysicsObject.h"
#include <iostream>

sfp::PhysicsObject::PhysicsObject(Bounds& bounds):
	bounds(bounds)
{
}

void sfp::PhysicsObject::setPosition(Vector2f center)
{
	bounds.setPosition(center);
}

Vector2f sfp::PhysicsObject::getPosition()
{
	return bounds.getPosition();
}

void sfp::PhysicsObject::visualizeBounds(RenderWindow& window)
{
	bounds.visualize(window);
}
