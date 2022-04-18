#pragma once
#include "PhysicsObject.h"

namespace sfp {
    class StaticPhysicsObject :
        public PhysicsObject
    {
    public:
        void applyImpulse(Vector2f impulse);
        Vector2f getVelocity();
        void setVelocity(Vector2f v);
    };
}


