#pragma once
#include "PhysicsObject.h"

namespace sfp {
    class DynamicPhysicsObject :
        public PhysicsObject
    {
    private:
        Vector2f velocity;

    public:
        DynamicPhysicsObject();
        DynamicPhysicsObject(Bounds& bounds,float restitution=1.0,
            float mass = 1.0);
        void applyImpulse(Vector2f impulse);
        void update(unsigned int deltaMilliseconds);
        Vector2f getVelocity();
        void setVelocity(Vector2f v);
    };

}


