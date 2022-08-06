#pragma once
#include "PhysicsShapeT.h"
#include "CircleBounds.h"
#include "CenteredConvexShape.h"

namespace sfp {
	class PhysicsConvexPolygon :
		public PhysicsShapeT<CenteredConvexShape, CircleBounds>
	{
	
	public:
		void setPoint(int ptIdx, Vector2f value);
		void resetBounds();
	};
}


