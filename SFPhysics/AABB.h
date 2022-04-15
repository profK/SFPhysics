#pragma once
#include <SFML/Graphics.hpp>
#include "Bounds.h"
#include "CollisionResult.h"




namespace sfp {
	class CircleBounds;

	class AABB: public Bounds
	{
	private:
		Vector2f min;
		Vector2f max;
	public:
		AABB(Vector2f min, Vector2f max);
		bool intersectsWith(AABB other);
		CollisionResult collideWith(AABB &other);
		CollisionResult collideWith(CircleBounds& other);
		Vector2f getPosition() {
			return (min+max)/2.0f;
		}

	};
}


