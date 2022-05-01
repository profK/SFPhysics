#pragma once
#include "CenteredRectangle.h"
#include "AABB.h"
#include "PhysicsShape.h"

namespace sfp {
    class PhysicsRectangle : public PhysicsShape<CenteredRectangle, AABB> 
    {};
}

