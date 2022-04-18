#include "pch.h"
#include "BoundsCollisionResult.h"

sfp::BoundsCollisionResult::BoundsCollisionResult(Bounds& object1, Bounds& object2):
	object1(object1),object2(object2)
{
	hasCollided = false;
	penetration = 0;
	normal = Vector2f(0, 0);
}

sfp::BoundsCollisionResult::BoundsCollisionResult(Bounds& object1, Bounds& object2,
	float penetration, Vector2f normal):
	object1(object1),object2(object2),penetration(penetration),normal(normal)
{
	hasCollided = true;
}
