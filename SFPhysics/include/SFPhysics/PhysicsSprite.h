#pragma once
#include "CenteredSprite.h"
#include "PhysicsShapeT.h"
#include "AABB.h"

namespace sfp {
    class PhysicsSprite :
        public PhysicsShapeT<CenteredSprite,AABB>
    {
    public:
        void setTexture(Texture& img);
    };
}

