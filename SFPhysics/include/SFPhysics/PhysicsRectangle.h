#pragma once
#include "CenteredRectangle.h"
#include "AABB.h"
#include "PhysicsShapeGlue.h"

namespace sfp {
    class PhysicsRectangle : public PhysicsShapeGlue<CenteredRectangle, AABB> 
    {
    public:
       
    };
}

