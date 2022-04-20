#pragma once
#include "CenteredRectangle.h"
#include "PhysicsShape.h"
#include "AABB.h"

namespace sfp {
    class PhysicsRectangleShape :
        public CenteredRectangle, public PhysicsShape, public AABB
    {
    public:
        PhysicsRectangleShape(Vector2f size, PhysicsObject& objectType);
    };
}

