#pragma once
#include <SFML/Graphics.hpp>
#include "CollisionResult.h"
#include "Bounds.h"

// forward refernce



namespace sfp {
	class AABB;

	class CircleBounds: public Bounds
	{
	private:
		Vector2f position;
		float radius;
	public:
		bool intersectsWith(CircleBounds& other);
		CollisionResult collideWith(AABB& other);
		CollisionResult collideWith(CircleBounds &other);
		Vector2f getPosition();
		float getRadius();
	};
}


