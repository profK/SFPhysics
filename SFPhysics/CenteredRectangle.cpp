#include "pch.h"
#include "CenteredRectangle.h"

sfp::CenteredRectangle::CenteredRectangle()
{
    setCenter(Vector2f(0.5, 0.5));
    setSize(Vector2f(1, 1));
}

sfp::CenteredRectangle::CenteredRectangle(Vector2f size):
    RectangleShape(size)
{
}

void sfp::CenteredRectangle::setCenter(Vector2f center)
{
    Vector2f size = getSize();
    RectangleShape::setPosition(center - (size / 2.0f));
}

Vector2f sfp::CenteredRectangle::getCenter()
{
    Vector2f size = getSize();
    return RectangleShape::getPosition() + (size / 2.0f);
}

void sfp::CenteredRectangle::setSize(Vector2f size)
{
    RectangleShape::setSize(size);
}

Vector2f sfp::CenteredRectangle::getSize()
{
    return RectangleShape::getSize();
}
