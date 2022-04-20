#include "pch.h"
#include "CenteredRectangle.h"

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
