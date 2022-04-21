#pragma once
#include "BoundsCollisionResult.h"
#include "PhysicsBody.h"



namespace sfp {
    class PhysicsBody;
    struct PhysicsBodyCollisionResult :
        public BoundsCollisionResult
    {

        PhysicsBody& object1;
        PhysicsBody& object2;

        PhysicsBodyCollisionResult(PhysicsBody& object1,
            PhysicsBody& object2, BoundsCollisionResult result);
    };
}


