#include "pch.h"
#include "CenteredCircle.h"

sfp::CenteredCircle::CenteredCircle(float radius):CircleShape(radius)
{
}

void sfp::CenteredCircle::setCenter(Vector2f center)
{
	float radius = getRadius();
	CircleShape::setPosition(center-Vector2f(radius,radius));
}

Vector2f sfp::CenteredCircle::getCenter()
{
	return CircleShape::getPosition();
}
