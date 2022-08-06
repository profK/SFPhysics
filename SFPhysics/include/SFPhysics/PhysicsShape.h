#pragma once
#include <SFML/Graphics.hpp>
#include "PhysicsBodyT.h"
#include "CenteredShape.h"
#include "Bounds.h"
#include <functional>

using namespace sf;

namespace sfp {

	class PhysicsShape
	{
	public:

		virtual void setCenter(Vector2f center) = 0;
		virtual void setSize(Vector2f size) = 0;
		virtual Vector2f getCenter() = 0;
		virtual Vector2f getSize() = 0;
		function<void(PhysicsBodyCollisionResult&)> onCollision = [this]
		(PhysicsBodyCollisionResult& result) {
			this->collisionCallback(result);
		};
		function<void(unsigned int)> onUpdate = [this]
		(unsigned int deltaMS) {
			this->updateCallback(deltaMS);
		};
		virtual void collisionCallback(
			PhysicsBodyCollisionResult& result) = 0;
		virtual void updateCallback(unsigned int deltaMs) = 0;
	};
}



