#include "pch.h"
#include "PhysicsShape.h"


sfp::PhysicsShape::PhysicsShape(CenteredShape& shape, Bounds& bounds, PhysicsObject& objectType):
	shape(shape),bounds(bounds),objectType(objectType)
{
}

Shape& sfp::PhysicsShape::getShape()
{
	return shape;
}

sfp::Bounds& sfp::PhysicsShape::getBounds()
{
	return bounds;
}

sfp::PhysicsObject& sfp::PhysicsShape::getPhysicsObject()
{
	return objectType;
}

void sfp::PhysicsShape::update(unsigned int deltaMS)
{
	shape.setCenter(objectType.getPosition());
}

void sfp::PhysicsShape::setCenter(Vector2f position)
{
	shape.setCenter(position);
	objectType.setPosition(position);
}
