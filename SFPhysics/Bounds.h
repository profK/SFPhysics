#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

namespace sfp {
	class Bounds
	{
	public:
		virtual Vector2f getPosition();
		virtual void visualize(RenderWindow& windoe);
	};
}


