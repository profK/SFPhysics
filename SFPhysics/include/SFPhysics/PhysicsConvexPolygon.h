#pragma once
#include "PhysicsShape.h"
#include "CircleBounds.h"
#include "CenteredConvexShape.h"

namespace sfp {
	class PhysicsConvexPolygon :
		public PhysicsShape<CenteredConvexShape, CircleBounds>
	{
	
	public:
		void setPoint(int ptIdx, Vector2f value);
		void resetBounds();
	};
}


