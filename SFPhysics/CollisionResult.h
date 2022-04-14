#pragma once
#include <SFML/Graphics.hpp>
#include "PhysicsObject.h"

using namespace sf;

namespace sfp {
	struct CollisionResult
	{
		bool hasCollided;
		PhysicsObject &object1;
		PhysicsObject &object2;
		float penetration;
		Vector2f normal;

		CollisionResult(PhysicsObject& object1, PhysicsObject& object2); // no collision
		CollisionResult(PhysicsObject& object1, PhysicsObject& object2,float penertration,
			Vector2f normal); // collision occured
	};
}


