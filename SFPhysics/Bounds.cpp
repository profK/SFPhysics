#include "pch.h"
#include "Bounds.h"
#include <iostream>
#include <typeinfo>
#include "CircleBounds.h"
#include "AABB.h"

using namespace sfp;

BoundsCollisionResult sfp::Bounds::collideWith(Bounds& other)
{
	if (typeid(other) == typeid(CircleBounds)) {
		return collideWithCircle(static_cast<CircleBounds&>(other));
	}
	else if (typeid(other) == typeid(AABB)) {
		return collideWithAABB(static_cast<AABB&>(other));
	}
}
