#pragma once
#include "CenteredRectangle.h"
#include "AABB.h"
#include "PhysicsBody.h"

namespace sfp {
    class PhysicsRectangle :
        public CenteredRectangle,public PhysicsBody
    {
    private:
        AABB defaultBounds;
    public:
        PhysicsRectangle(Vector2f center, Vector2f size, bool isStatic = false);
    };
}

