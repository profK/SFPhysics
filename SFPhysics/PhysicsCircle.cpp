#include "pch.h"
#include "PhysicsCircle.h"

sfp::PhysicsCircle::PhysicsCircle(Vector2f center, float radius, bool isStatic):
	CenteredCircle(radius),CircleBounds(center,radius),PhysicsBody(*this,isStatic)
{
	setCenter(center);
}
