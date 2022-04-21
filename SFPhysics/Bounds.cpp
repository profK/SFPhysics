#include "pch.h"
#include "Bounds.h"
#include <iostream>
#include <typeinfo>
#include "CircleBounds.h"
#include "AABB.h"

using namespace sfp;

BoundsCollisionResult sfp::Bounds::reverseCollsionObjects(BoundsCollisionResult result)
{
	if (result.hasCollided) {
		return BoundsCollisionResult(result.object2, result.object1, result.penetration,
			result.normal * -1.0f);
	}
	else {
		return BoundsCollisionResult(result.object2, result.object1);
	}
}

void sfp::Bounds::setPosition(Vector2f center)
{
	//nop
}


