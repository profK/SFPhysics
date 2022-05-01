#pragma once
#include "CenteredShape.h"
#include <SFML/Graphics.hpp>

using namespace sf;

namespace sfp {
    class CenteredRectangle :
        public CenteredShape, public RectangleShape
    {
    public:
        CenteredRectangle();
        CenteredRectangle(Vector2f size);
        // Inherited via CenterPositionedShape
        virtual void setCenter(Vector2f center) override;
        virtual Vector2f getCenter() override;
        virtual void setSize(Vector2f size) override;
        virtual Vector2f getSize() override;
    };
}

