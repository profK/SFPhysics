#pragma once
#include <SFML/Graphics.hpp>
#include "Bounds.h"

using namespace sf;

namespace sfp {
	struct BoundsCollisionResult
	{
		bool hasCollided;
		Bounds& object1;
		Bounds& object2;
		float penetration;
		Vector2f normal;

		BoundsCollisionResult(Bounds& object1, Bounds& object2); // no collision
		BoundsCollisionResult(Bounds& object1, Bounds& object2,float penertration,
			Vector2f normal); // collision occured
	};
}


