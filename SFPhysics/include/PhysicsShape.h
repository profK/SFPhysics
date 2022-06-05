#pragma once
#include "CenteredShape.h"
#include "PhysicsBody.h"

namespace sfp {
	class PhysicsShape {

		public:
			virtual PhysicsBody& getBody()=0;
			virtual Drawable& getDrawable() = 0;
			virtual CenteredShape& getShape() = 0;
			virtual void setCenter(Vector2f center) = 0;
			virtual void setSize(Vector2f size) = 0;
			virtual Vector2f getCenter() = 0;
			virtual Vector2f getSize() = 0;
			virtual PhysicsShape& clone()=0;
	};
}