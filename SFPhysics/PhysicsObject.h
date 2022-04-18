#pragma once
#include <SFML/Graphics.hpp>
#include "Bounds.h"

using namespace sf;

namespace sfp {
	class PhysicsObject
	{
	protected:
		Bounds& bounds;
	public:
		PhysicsObject(Bounds& bounds);
		virtual void applyImpulse(Vector2f impulse)=0;
		virtual void update(unsigned int deltaMillisconds)=0;
		void setPosition(Vector2f center);
		Vector2f getPosition();
		void visualizeBounds(RenderWindow& window);

	};
}


