#include "pch.h"
#include "AABB.h"
#include <math.h>
#include "CircleBounds.h"



sfp::AABB::AABB(Vector2f min, Vector2f max):
    min(min),max(max)
{
}

bool sfp::AABB::intersectsWith(AABB other)
{
    // Exit with no intersection if found separated along an axis
    if ((max.x < other.min.x) || (min.x > other.max.x)) return false;
    if ((max.y < other.min.y) || (min.y > other.max.y)) return false;

            // No separating axis found, therefor there is at least one overlapping axis
    return true;
}

sfp::BoundsCollisionResult sfp::AABB::collideWithAABB(AABB &other)
{
   
// Setup a couple pointers to each object
    AABB* A = this;
    AABB* B = &other;

    // Vector from A to B
    Vector2f n = B->getPosition() - A->getPosition();

// Calculate half extents along x axis for each object
    float a_extent = (max.x - min.x) / 2;
    float b_extent = (other.max.x - other.min.x) / 2;

// Calculate overlap on x axis
    float x_overlap = a_extent + b_extent - abs(n.x);

// SAT test on x axis
    if (x_overlap > 0)
    {
    // Calculate half extents along y axis for each object
        float a_extent = (max.y - min.y) / 2;
        float b_extent = (other.max.y - other.min.y) / 2;

        // Calculate overlap on y axis
        float y_overlap = a_extent + b_extent - abs(n.y);

        // SAT test on y axis
        if (y_overlap > 0)
        {
            // Find out which axis is axis of least penetration
            if (x_overlap > y_overlap)
            {
                // Point towards B knowing that n points from A to B
                Vector2f normal;
             
                if (n.x < 0)
                    normal = Vector2f(-1, 0);
                else
                    normal = Vector2f(0, 0);
                return BoundsCollisionResult(*this, other, x_overlap, normal);
            }
            else
            {
                Vector2f normal;
                // Point toward B knowing that n points from A to B
                if (n.y < 0)
                    normal = Vector2f(0, -1);
                else
                    normal = Vector2f(0, 1);
                return BoundsCollisionResult(*this, other, y_overlap, normal);
            }
        }
    }
    return BoundsCollisionResult(*this, other);
}

static double clamp(double d, double min, double max) {
    const double t = d < min ? min : d;
    return t > max ? max : t;
}

sfp::BoundsCollisionResult sfp::AABB::collideWithCircle(CircleBounds& other) {
        // Setup a couple pointers to each object
  
    // Setup a couple pointers to each object
    Bounds* A = this;
    Bounds* B = &other;

        // Vector from A to B
    Vector2f n = B->getPosition() - A->getPosition();

    // Closest point on A to center of B
    Vector2f closest = n;

        // Calculate half extents along each axis
    float x_extent = (max.x - min.x) / 2;
    float y_extent = (max.y - min.y) / 2;

        // Clamp point to edges of the AABB
    closest.x = clamp(closest.x,-x_extent, x_extent);
    closest.y = clamp(closest.y,-y_extent, y_extent);

    bool inside = false;

    // Circle is inside the AABB, so we need to clamp the circle's center
    // to the closest edge
    if (n == closest)
    {
        inside = true;

            // Find closest axis
        if (abs(n.x) > abs(n.y))
        {
            // Clamp to closest extent
            if (closest.x > 0)
                closest.x = x_extent;
            else
                closest.x = -x_extent;
        }

        // y axis is shorter
        else
        {
            // Clamp to closest extent
            if (closest.y > 0)
                closest.y = y_extent;
            else
                closest.y = -y_extent;
        }
    }

    Vector2f normal = n - closest;
    double d = pow(normal.x, 2) + pow(normal.y, 2);
    double r = other.getRadius();

    // Early out of the radius is shorter than distance to closest point and
    // Circle not inside the AABB
    if (d > r * r && !inside)
        return BoundsCollisionResult(*this, other);

    // Avoided sqrt until we needed
    d = sqrt(d);

    // Collision normal needs to be flipped to point outside if circle was
    // inside the AABB
    n = Vector2f(normal.x / d, normal.y / d);
    if (inside)
    {
        Vector2f normal = -n;
        double penetration = r - d;
        return BoundsCollisionResult(*this, other,penetration,normal);
    }
    else
    {
        Vector2f normal = n;
        double penetration = r - d;
        return BoundsCollisionResult(*this, other, penetration, normal);
    }

  
}

Vector2f sfp::AABB::getPosition()
{
    
    return min + (max - min) / 2.0f;
    
}

void sfp::AABB::setPosition(Vector2f center)
{
    //TODO: Check to make sure not off by 1
    Vector2f halfSize = (max - min)/2.0f;
    min = center - halfSize;
    max = center + halfSize;
}

void sfp::AABB::visualize(RenderWindow& window)
{
    RectangleShape shape(max - min);
    shape.setPosition(min);
    shape.setFillColor(Color::Transparent);
    shape.setOutlineColor(Color::White);
    shape.setOutlineThickness(2);
    window.draw(shape);
}
