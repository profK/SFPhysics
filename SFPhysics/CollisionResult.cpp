#include "pch.h"
#include "CollisionResult.h"

sfp::CollisionResult::CollisionResult(PhysicsObject& object1, PhysicsObject& object2):
	object1(object1),object2(object2)
{
	hasCollided = false;
	penetration = 0;
	normal = Vector2f(0, 0);
}

sfp::CollisionResult::CollisionResult(PhysicsObject& object1, PhysicsObject& object2, 
	float penertration, Vector2f normal):
	object1(object1),object2(object2),penetration(penetration),normal(normal)
{
	hasCollided = true;
}
