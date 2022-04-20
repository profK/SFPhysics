#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

namespace sfp{
    class CenteredShape :
        public Shape
    {
    public:
        virtual void setCenter(Vector2f center)=0;
        virtual Vector2f getCenter()=0;
    };
}

