#include "pch.h"
#include "PhysicsCircleShape.h"
#include "CenteredCircle.h"

sfp::PhysicsCircleShape::PhysicsCircleShape(Vector2f center, float radius,
	PhysicsObject& physicsType) :
	CircleBounds(center, radius),
	CenteredCircle(radius),
	PhysicsShape(*this,*this,physicsType)
{

}


