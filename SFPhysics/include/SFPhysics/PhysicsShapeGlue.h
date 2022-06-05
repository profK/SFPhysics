#pragma once
#include <SFML/Graphics.hpp>
#include "PhysicsBody.h"
#include "PhysicsShape.h"
#include "CenteredShape.h"
#include "Bounds.h"

using namespace sf;

namespace sfp {

	template <class ShapeClass, class BoundsClass>
	class PhysicsShapeGlue: public PhysicsShape
	{
	protected:
		PhysicsBody body;
		BoundsClass bounds;
		ShapeClass shape;

	public:
		PhysicsShapeGlue();
		PhysicsShapeGlue(const PhysicsShapeGlue& other);
		virtual PhysicsShapeGlue& operator = (const PhysicsShapeGlue& other);
		virtual PhysicsBody& getBody();
		virtual CenteredShape& getShape();
		virtual void setCenter(Vector2f center);
		virtual void setSize(Vector2f size);
		virtual Vector2f getCenter();
		virtual Vector2f getSize();
		virtual void collisionCallback(
			PhysicsBodyCollisionResult& result);
		virtual void updateCallback(unsigned int deltaMs);
		virtual PhysicsShape& clone();

		// Inherited via PhysicsShape
		virtual Drawable& getDrawable() override
		{
			return (Drawable&)shape;
		}
	};

	
	template<class ShapeClass, class BoundsClass>
	inline PhysicsShapeGlue<ShapeClass, BoundsClass>::PhysicsShapeGlue():
		body(bounds)
	{
		//static_assert(std::is_base_of<CenteredShape, ShapeClass>::value, 
		//	"type parameter of this class must derive from CenteredShape");
		//static_assert(std::is_base_of<BoundsClass, Bounds>::value,
		//	"type parameter of this class must derive from Bounds");
	}

	
	template<class ShapeClass, class BoundsClass>
	inline PhysicsShapeGlue<ShapeClass, BoundsClass>::PhysicsShapeGlue(const PhysicsShapeGlue& other) :
		body(bounds)
	{
		body = other.body;
		bounds = other.bounds;
		shape = other.shape;
		
	}
	template<class ShapeClass, class BoundsClass>
	inline PhysicsShapeGlue<ShapeClass, BoundsClass>& PhysicsShapeGlue<ShapeClass, BoundsClass>::operator=(
		const PhysicsShapeGlue<ShapeClass,BoundsClass>& other)
	{
		body = other.body;
		bounds = other.bounds;
		shape = other.shape;
		return *this;
	}
	
	template<class ShapeClass, class BoundsClass>
	 PhysicsBody& PhysicsShapeGlue<ShapeClass, BoundsClass>::getBody()
	{
		return body;
	}

	template<class ShapeClass, class BoundsClass>
	 CenteredShape& PhysicsShapeGlue<ShapeClass, BoundsClass>::getShape()
	{
		return dynamic_cast<CenteredShape&>(shape);
	}

	template<class ShapeClass, class BoundsClass>
	 void PhysicsShapeGlue<ShapeClass, BoundsClass>::setCenter(Vector2f center)
	{
		bounds.setPosition(center);
		shape.setCenter(center);
	}
	template<class ShapeClass, class BoundsClass>
	 void PhysicsShapeGlue<ShapeClass, BoundsClass>::setSize(Vector2f size)
	{
		bounds.setSize(size);
		shape.setSize(size);
	}
	template<class ShapeClass, class BoundsClass>
	 Vector2f PhysicsShapeGlue<ShapeClass, BoundsClass>::getCenter()
	{
		return shape.getCenter();
	}
	template<class ShapeClass, class BoundsClass>
	 Vector2f PhysicsShapeGlue<ShapeClass, BoundsClass>::getSize()
	{
		return shape.getSize();
	}

	template<class ShapeClass, class BoundsClass>
	 void PhysicsShapeGlue<ShapeClass, BoundsClass>::collisionCallback(PhysicsBodyCollisionResult& result)
	{
		//nop
	}

	template<class ShapeClass, class BoundsClass>
	 void PhysicsShapeGlue<ShapeClass, BoundsClass>::updateCallback(unsigned int deltaMs)
	{
		//nop
	}

	 template<class ShapeClass, class BoundsClass>
	 inline PhysicsShape& PhysicsShapeGlue<ShapeClass, BoundsClass>::clone()
	 {
			 PhysicsShapeGlue<ShapeClass, BoundsClass>& clone =
				 *new PhysicsShapeGlue<ShapeClass, BoundsClass>(*this);
			 return clone;
	 }
	
}



