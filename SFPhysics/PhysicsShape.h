#pragma once
#include <SFML/Graphics.hpp>
#include "PhysicsBody.h"

using namespace sf;

namespace sfp {

	template <class ShapeClass, class BoundsClass>
	class PhysicsShape
	{
	protected:
		PhysicsBody body;
		ShapeClass shape;
		BoundsClass defaultBounds;

	public:
		PhysicsShape();
		PhysicsBody getBody();
		ShapeClass getShape();
		void setCenter(Vector2f center);
		void setSize(Vector2f size);
		Vector2f getCenter();
		Vector2f getSize();
	};
}



