#pragma once
#include <SFML/Graphics.hpp>
#include "CollisionResult.h"

// forward refernce



namespace sfp {
	class AABB;

	class Circle: public PhysicsObject
	{
	private:
		Vector2f position;
		float radius;
	public:
		bool intersectsWith(Circle other);
		CollisionResult collideWith(AABB& other);
		CollisionResult collideWith(Circle &other);
		Vector2f getPosition();
		float getRadius();
	};
}


