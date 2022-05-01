#pragma once
#include <SFML/Graphics.hpp>
#include "CenteredShape.h"

using namespace sf;
namespace sfp {
	class CenteredConvexShape :
		public ConvexShape, CenteredShape
	{
	public:
		// Inherited via CenteredShape
		virtual void setCenter(Vector2f center) override;
		virtual Vector2f getCenter() override;
		virtual void setSize(Vector2f size) override;
		virtual Vector2f getSize() override;
	};
 }


