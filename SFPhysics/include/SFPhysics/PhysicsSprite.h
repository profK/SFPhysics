#pragma once
#include "CenteredSprite.h"
#include "PhysicsShapeGlue.h"
#include "AABB.h"

namespace sfp {
    class PhysicsSprite :
        public PhysicsShapeGlue<CenteredSprite,AABB>
    {
    public:
        void setTexture(Texture& img);

    };
}

