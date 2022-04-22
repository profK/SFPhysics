#include "pch.h"
#include "PhysicsCircle.h"

sfp::PhysicsCircle::PhysicsCircle(Vector2f center, float radius, bool isStatic):
	defaultBounds(center,radius),
	CenteredCircle(radius),PhysicsBody(defaultBounds,isStatic)
{
	setCenter(center);
	getBounds().onMove = [this](Vector2f center) {
		CenteredCircle::setCenter(center);
	};
}

void sfp::PhysicsCircle::setCenter(Vector2f center)
{
	CenteredCircle::setCenter(center);
	bounds->setPosition(center);
}




