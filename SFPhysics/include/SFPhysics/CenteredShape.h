#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

namespace sfp{
    class CenteredShape
    {
    public:
        virtual void setCenter(Vector2f center)=0;
        virtual Vector2f getCenter()=0;
        virtual void setSize(Vector2f size) = 0;
        virtual Vector2f getSize() = 0;
    };
}

