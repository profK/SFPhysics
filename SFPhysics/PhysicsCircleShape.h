#pragma once
#include <SFML/Graphics.hpp>
#include "PhysicsObject.h"
#include "World.h"
#include "CircleBounds.h"
#include "PhysicsShape.h"
#include "CenteredCircle.h"

using namespace sf;

namespace sfp {
	class PhysicsCircleShape :
		public CenteredCircle, public PhysicsShape, public CircleBounds
	{
	
	public:
		PhysicsCircleShape(Vector2f center, 
			float radius, PhysicsObject& physicsType);
	};

}

class PhysicsCircleShape :
	public CircleShape
{
};



