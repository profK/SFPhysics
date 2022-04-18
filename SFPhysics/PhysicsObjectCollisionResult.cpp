#include "pch.h"
#include "PhysicsObjectCollisionResult.h"
#include "PhysicsObject.h"



sfp::PhysicsObjectCollisionResult::PhysicsObjectCollisionResult(
	PhysicsObject& object1, PhysicsObject& object2, 
	BoundsCollisionResult result):
	object1(object1), object2(object2), BoundsCollisionResult(result)
{
}
