#pragma once
#include "PhysicsBody.h"
namespace sfp{

    template <class BoundsClass>
    class PhysicsBodyT :
        public PhysicsBody
    {
    private:
        BoundsClass bounds;
        // Inherited via PhysicsBody
    public:
        virtual Bounds& getBounds() override {
            return bounds;
        }
    };

}

