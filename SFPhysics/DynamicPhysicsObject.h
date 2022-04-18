#pragma once
#include "PhysicsObject.h"

namespace sfp {
    class DynamicPhysicsObject :
        public PhysicsObject
    {
    private:
        Vector2f velocity;

    public:
        DynamicPhysicsObject(Bounds& bounds);
        void applyImpulse(Vector2f impulse);
        void update(unsigned int deltaMilliseconds);

    };

}


