#include "pch.h"
#include "PhysicsBodyCollisionResult.h"
#include "PhysicsBody.h"



sfp::PhysicsBodyCollisionResult::PhysicsBodyCollisionResult(
	PhysicsBody& object1, PhysicsBody& object2, 
	BoundsCollisionResult result):
	object1(object1), object2(object2), BoundsCollisionResult(result)
{
}
