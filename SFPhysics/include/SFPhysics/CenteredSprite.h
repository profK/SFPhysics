#pragma once
#include "CenteredShape.h"

namespace sfp {

    class CenteredSprite :
        public CenteredShape, public Sprite
    {
    public:
        CenteredSprite();
        CenteredSprite(Texture& tex);

        void setImage(Texture& img);
        Texture& getImage();

        // Inherited via CenteredShape
        virtual void setCenter(Vector2f center) override;
        virtual Vector2f getCenter() override;
        virtual void setSize(Vector2f size) override;
        virtual Vector2f getSize() override;

        
    };
}

