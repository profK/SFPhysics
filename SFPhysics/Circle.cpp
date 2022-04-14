#include "pch.h"
#include "Circle.h"
#include <math.h>
#include "AABB.h"

using namespace std;

bool sfp::Circle::intersectsWith(Circle other)
{
	float r = radius + other.radius;
	r *= r;
	return r < (powf(position.x + other.position.x,2) + powf(position.y + other.position.y, 2));
}

sfp::CollisionResult sfp::Circle::collideWith(Circle &other)
{
    // Setup a couple pointers to each object
    Circle* A = this;
    Circle* B = &other;
    

    // Vector from A to B
    Vector2f n = B->position - A->position;
    float distSquared = powf(n.x, 2) + powf(n.y, 2);

    float r = A->radius + B->radius;
    r *= r;

    if (distSquared > r) {
        return CollisionResult(*this, other);
    }

    // Circles have collided, now compute manifold
    float d = sqrt(distSquared); // perform actual sqrt

    // If distance between circles is not zero
    if (d != 0)
    {
        // Distance is difference between radius and distance
        float penetration = r - d;

        // Utilize our d since we performed sqrt on it already within Length( )
        // Points from A to B, and is a unit vector
        Vector2f normal = (position-other.position) / d;
        return CollisionResult(*this, other, penetration, normal);
    }

// Circles are on same position
    else
    {
        // Choose random (but consistent) values
        float penetration = A->radius;
        Vector2f normal = Vector2f(1, 0);
        return CollisionResult(*this, other, penetration, normal);
    }
}

sfp::CollisionResult sfp::Circle::collideWith(AABB& other)
{
    return other.collideWith(*this);
}

Vector2f sfp::Circle::getPosition()
{
    return position;
}

float sfp::Circle::getRadius()
{
    return radius;
}
