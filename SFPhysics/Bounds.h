#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

namespace sfp {
	class Bounds
	{
	public:
		virtual Vector2f getPosition() = 0;
		virtual void setPosition(Vector2f center)=0;
		virtual void visualize(RenderWindow& window)=0;
	};
}


