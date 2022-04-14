#pragma once
#include <SFML/Graphics.hpp>
#include "PhysicsObject.h"
#include "CollisionResult.h"




namespace sfp {
	class Circle;

	class AABB: public PhysicsObject
	{
	private:
		Vector2f min;
		Vector2f max;
	public:
		bool intersectsWith(AABB other);
		CollisionResult collideWith(AABB &other);
		CollisionResult collideWith(Circle& other);
		Vector2f getPosition() {
			return (min+max)/2.0f;
		}

	};
}


