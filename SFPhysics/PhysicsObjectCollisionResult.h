#pragma once
#include "BoundsCollisionResult.h"



namespace sfp {
    class PhysicsObject;
    struct PhysicsObjectCollisionResult :
        public BoundsCollisionResult
    {

        PhysicsObject& object1;
        PhysicsObject& object2;

        PhysicsObjectCollisionResult(PhysicsObject& object1,
            PhysicsObject& object2, BoundsCollisionResult result);
    };
}


