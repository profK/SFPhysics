#pragma once
#include "CenteredShape.h"
#include <SFML/Graphics.hpp>

using namespace sf;

namespace sfp {
    class CenteredRectangle :
        public CenteredShape, public RectangleShape
    {
        // Inherited via CenterPositionedShape
        virtual void setCenter(Vector2f center) override;
        virtual Vector2f getCenter() override;
    };
}

