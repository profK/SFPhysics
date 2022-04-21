#pragma once
#include <SFML/Graphics.hpp>
#include "BoundsCollisionResult.h"
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
		CircleBounds();
		CircleBounds(Vector2f position, float radius);
		bool intersectsWith(CircleBounds& other);
		BoundsCollisionResult collideWith(Bounds& other);
		BoundsCollisionResult collideWithAABB(AABB& other);
		BoundsCollisionResult collideWithCircle(CircleBounds &other);
		Vector2f getPosition();
		void setPosition(Vector2f center);
		void setRadius(float r);
		float getRadius();
		void visualize(RenderWindow& window);
	};
}


