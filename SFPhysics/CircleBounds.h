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
		CircleBounds(Vector2f position, float radius);
		bool intersectsWith(CircleBounds& other);
		CollisionResult collideWith(AABB& other);
		CollisionResult collideWith(CircleBounds &other);
		Vector2f getPosition();
		void setPosition(Vector2f center);
		float getRadius();
		void visualize(RenderWindow& window);
	};
}


