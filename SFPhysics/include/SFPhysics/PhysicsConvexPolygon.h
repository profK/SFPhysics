#pragma once
#include "PhysicsShapeGlue.h"
#include "CircleBounds.h"
#include "CenteredConvexShape.h"

namespace sfp {
	class PhysicsConvexPolygon :
		public PhysicsShapeGlue<CenteredConvexShape, CircleBounds>
	{
	
	public:
		void setPoint(int ptIdx, Vector2f value);
		void resetBounds();
	};
}


