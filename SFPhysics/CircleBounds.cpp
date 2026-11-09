#include "pch.h"
#include "CircleBounds.h"
#include <math.h>
#include "AABB.h"

using namespace std;

sfp::CircleBounds::CircleBounds() :
    CircleBounds(Vector2f(0.5, 0.5), 1)
{
}

sfp::CircleBounds::CircleBounds(Vector2f position, float radius):
    position(position), radius(radius), visual(10.0f)
{
}

bool sfp::CircleBounds::intersectsWith(CircleBounds& other)
{
    float dx = position.x - other.position.x;
    float dy = position.y - other.position.y;

    float r = radius + other.radius;

    return dx * dx + dy * dy <= r * r;
}

sfp::BoundsCollisionResult sfp::CircleBounds::collideWith(Bounds& other)
{
    return reverseCollsionObjects(other.collideWithCircle(*this));
}


sfp::BoundsCollisionResult
sfp::CircleBounds::collideWithCircle(CircleBounds& other)
{
    CircleBounds* A = this;
    CircleBounds* B = &other;

    // Vector from A to B
    Vector2f n = B->position - A->position;

    float distSquared = n.x * n.x + n.y * n.y;

    float r = A->radius + B->radius;

    // No collision
    if (distSquared > r * r) {
        return BoundsCollisionResult(*this, other);
    }

    // Circles overlap
    float d = sqrtf(distSquared);

    if (d != 0.0f)
    {
        float penetration = r - d;

        // Correct: normal points from A toward B
        Vector2f normal = n / d;

        return BoundsCollisionResult(
            *this, other, penetration, normal
        );
    }
    else
    {
        // Same center: arbitrary normal
        float penetration = r;
        Vector2f normal(1.0f, 0.0f);

        return BoundsCollisionResult(
            *this, other, penetration, normal
        );
    }
}


sfp::BoundsCollisionResult sfp::CircleBounds::collideWithAABB(AABB& other)
{
    BoundsCollisionResult result = other.collideWithCircle(*this);
    if (result.hasCollided) {
        //have to reverse bounds and normal
        return BoundsCollisionResult(result.object2, result.object1,
            result.penetration, result.normal * -1.0f);
    }
    return result;
}

Vector2f sfp::CircleBounds::getPosition()
{
    return position;
}

void sfp::CircleBounds::setPosition(Vector2f center)
{
    if (onMove){
        onMove(center);
    }
   
    position = center;
}

void sfp::CircleBounds::setRadius(float r)
{
    radius = r;
}

float sfp::CircleBounds::getRadius()
{
    return radius;
}

void sfp::CircleBounds::setSize(Vector2f extents)
{
    setRadius(max(extents.x, extents.y)/2);
}

Vector2f sfp::CircleBounds::getSize()
{
    return Vector2f(radius,radius);
}

void sfp::CircleBounds::visualize(RenderWindow& window)
{
    visual.setRadius(radius);
    visual.setPosition(position-Vector2f(radius,radius));
    visual.setFillColor(Color::Transparent);
    visual.setOutlineColor(Color::White);
    visual.setOutlineThickness(2);
    window.draw(visual);
}
