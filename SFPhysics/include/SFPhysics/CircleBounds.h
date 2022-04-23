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
		CircleShape visual;
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
		/// <summary>
		/// Uses the smaller of the extents as the radius
		/// </summary>
		/// <param name="extents"></param>
		virtual void setSize(Vector2f extents) override;
		/// <summary>
		/// returns the radius in x and y
		/// </summary>
		/// <returns></returns>
		virtual Vector2f getSize() override;
		void visualize(RenderWindow& window);
	};
}


