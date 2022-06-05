#include "pch.h"
#include "CenteredCircle.h"

sfp::CenteredCircle::CenteredCircle():CircleShape()
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

void sfp::CenteredCircle::setSize(Vector2f sz)
{
	Vector2f center = getCenter();
	float radius = std::min(sz.x, sz.y);
	setRadius(radius);
	setCenter(center);
}

Vector2f sfp::CenteredCircle::getSize()
{
	float radius = getRadius();
	Vector2f val(radius, radius);
	return val;
}
