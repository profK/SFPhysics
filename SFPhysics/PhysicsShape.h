#pragma once
#include <SFML/Graphics.hpp>
#include "Bounds.h"
#include "PhysicsObject.h"
#include "CenteredShape.h"

using namespace sf;

namespace sfp{
	class PhysicsShape
	{
	private:
		CenteredShape& shape;
		Bounds& bounds;
		PhysicsObject& objectType;
	public:
		PhysicsShape(CenteredShape& shape, Bounds& bounds, PhysicsObject& objectType);
		Shape& getShape();
		Bounds& getBounds();
		PhysicsObject& getPhysicsObject();
		virtual void update(unsigned int deltaMS);
		void setCenter(Vector2f position);
	};
}


