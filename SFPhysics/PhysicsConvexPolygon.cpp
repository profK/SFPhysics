#include "pch.h"
#include "PhysicsConvexPolygon.h"

using namespace sfp;

void sfp::PhysicsConvexPolygon::resetBounds()
{
	FloatRect bounds = shape.getGlobalBounds();
	body.getBounds().setSize(Vector2f(bounds.width, bounds.height));
	
}

void sfp::PhysicsConvexPolygon::setPoint(int ptIdx, Vector2f value)
{
	shape.setPoint(ptIdx, value);
	resetBounds();
}
