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
      
        PhysicsRectangle(Vector2f center=Vector2f(25,25), Vector2f size=Vector2f(50,50), bool isStatic = false);
    };
}

