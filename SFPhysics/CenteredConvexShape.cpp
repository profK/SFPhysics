#include "pch.h"
#include "CenteredConvexShape.h"

void sfp::CenteredConvexShape::setCenter(Vector2f center)
{
    setPosition(center);
}

Vector2f sfp::CenteredConvexShape::getCenter()
{
    return getPosition();
}

void sfp::CenteredConvexShape::setSize(Vector2f size)
{
    FloatRect bounds = getLocalBounds();
    setScale(Vector2f(size.x / bounds.width, size.y / bounds.height));
}

Vector2f sfp::CenteredConvexShape::getSize()
{
    Vector2f scale = getScale();
    FloatRect bounds =getLocalBounds();
    return Vector2f(scale.x*bounds.width,scale.y*bounds.height);
}
