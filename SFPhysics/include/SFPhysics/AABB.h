#pragma once
#include <SFML/Graphics.hpp>
#include "Bounds.h"
#include "BoundsCollisionResult.h"




namespace sfp {
	class CircleBounds;

	class AABB: public Bounds
	{
	private:
		Vector2f min;
		Vector2f max;
		RectangleShape visual;
	public:
		AABB();
		AABB(Vector2f min, Vector2f max);
		bool intersectsWith(AABB other);
		BoundsCollisionResult collideWith(Bounds& other);
		BoundsCollisionResult collideWithAABB(AABB &other);
		BoundsCollisionResult collideWithCircle(CircleBounds& other);
		Vector2f getPosition();
		void setPosition(Vector2f center);
		virtual void setSize(Vector2f extents) override;
		virtual Vector2f getSize() override;
		void visualize(RenderWindow& window);

	};
}


