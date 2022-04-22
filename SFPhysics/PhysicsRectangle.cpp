#include "pch.h"
#include "PhysicsRectangle.h"


sfp::PhysicsRectangle::PhysicsRectangle(Vector2f center, Vector2f size, bool isStatic):
	defaultBounds(center - (size / 2.0f), center + (size / 2.0f)),
	CenteredRectangle(size),
	PhysicsBody(defaultBounds,isStatic)
{
	setCenter(center);
	getBounds().onMove = [this](Vector2f center) {
		CenteredRectangle::setCenter(center);
	};
}

void sfp::PhysicsRectangle::setCenter(Vector2f center) {
	PhysicsBody::getBounds().setPosition(center);
	CenteredRectangle::setCenter(center);
}
