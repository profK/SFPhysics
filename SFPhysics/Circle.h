#pragma once
#include <SFML/Graphics.hpp>
#include "CollisionResult.h"
#include "AABB.h";

using namespace sf;

namespace sfp {
	class Circle: public PhysicsObject
	{
	private:
		Vector2f position;
		float radius;
	public:
		bool intersectsWith(Circle other);
		CollisionResult collideWith(Circle &other);
		CollisionResult collideWith(AABB& other);
		Vector2f getPosition();
		float getRadius();
	};
}


