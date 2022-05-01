#pragma once
#include "CenteredSprite.h"
#include "PhysicsShape.h"
#include "AABB.h"

namespace sfp {
    class PhysicsSprite :
        public PhysicsShape<CenteredSprite,AABB>
    {
    public:
        void setTexture(Texture& img);
    };
}

