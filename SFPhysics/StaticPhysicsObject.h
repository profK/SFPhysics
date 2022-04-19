#pragma once
#include "PhysicsObject.h"

namespace sfp {
    class StaticPhysicsObject :
        public PhysicsObject
    {
    public:
        StaticPhysicsObject(Bounds& bounds);
        void applyImpulse(Vector2f impulse);
        Vector2f getVelocity();
        void setVelocity(Vector2f v);

        // Inherited via PhysicsObject
        virtual void update(unsigned int deltaMillisconds) override;
    };
}


