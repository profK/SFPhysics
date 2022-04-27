#pragma once
#include "CenteredSprite.h"
#include "PhysicsBody.h"
#include "AABB.h"

namespace sfp {
    class PhysicsSprite :
        public CenteredSprite, public PhysicsBody
    {

    private:
        AABB defaultBounds;
    public:
        PhysicsSprite();
        PhysicsSprite(Texture& tex, bool isStatic = false);
        void setImage(Texture& img);
        void setCenter(Vector2f center);
    };
}

