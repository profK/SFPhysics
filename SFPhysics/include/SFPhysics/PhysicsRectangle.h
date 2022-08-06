#pragma once
#include "CenteredRectangle.h"
#include "AABB.h"
#include "PhysicsShapeT.h"

namespace sfp {
    class PhysicsRectangle : public PhysicsShapeT<CenteredRectangle, AABB> 
    {};
}

