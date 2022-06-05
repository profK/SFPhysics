#pragma once
#include <SFML/Graphics.hpp>
#include "PhysicsBody.h"
#include "CenteredShape.h"
#include "Bounds.h"

using namespace sf;

namespace sfp {

	template <class ShapeClass, class BoundsClass>
	class PhysicsShape
	{
	protected:
		PhysicsBody body;
		BoundsClass bounds;
		ShapeClass shape;

	public:
		PhysicsShape();
		PhysicsShape(const PhysicsShape& other);
		PhysicsShape& operator = (PhysicsShape other) {
			body = other.body;
			bounds = other.bounds;
			body.setBounds(bounds);
			shape = other.shape; 
			return *this;
		}
		PhysicsBody& getBody();
		ShapeClass& getShape();
		void setCenter(Vector2f center);
		void setSize(Vector2f size);
		Vector2f getCenter();
		Vector2f getSize();
		virtual void collisionCallback(
			PhysicsBodyCollisionResult& result);
		virtual void updateCallback(unsigned int deltaMs);
	};

	template<class ShapeClass, class BoundsClass>
	inline PhysicsShape<ShapeClass, BoundsClass>::PhysicsShape():
		body(bounds)
	{
		//static_assert(std::is_base_of<CenteredShape, ShapeClass>::value, 
		//	"type parameter of this class must derive from CenteredShape");
		//static_assert(std::is_base_of<BoundsClass, Bounds>::value,
		//	"type parameter of this class must derive from Bounds");

		bounds.onMove = [this](Vector2f pos) {
			this->getShape().setCenter(pos);
		};
		body.onCollision = [this](PhysicsBodyCollisionResult& result) {
			collisionCallback(result);
		};
		body.onUpdate = [this](unsigned int deltaMs) {
			updateCallback(deltaMs);
		};

	}
	template<class ShapeClass, class BoundsClass>
	inline PhysicsShape<ShapeClass, BoundsClass>::PhysicsShape(const PhysicsShape& other)
	{
		body = other.body;
		body.setBounds(bounds);
		shape = other.shape;
		bounds = other.bounds;
		bounds.onMove = [this](Vector2f pos) {
			this->getShape().setCenter(pos);
		};
		body.onCollision = [this](PhysicsBodyCollisionResult& result) {
			collisionCallback(result);
		};
		body.onUpdate = [this](unsigned int deltaMs) {
			updateCallback(deltaMs);
		};
	}

	

	
	
	template<class ShapeClass, class BoundsClass>
	inline PhysicsBody& PhysicsShape<ShapeClass, BoundsClass>::getBody()
	{
		return body;
	}
	template<class ShapeClass, class BoundsClass>
	inline ShapeClass& PhysicsShape<ShapeClass, BoundsClass>::getShape()
	{
		return shape;
	}
	template<class ShapeClass, class BoundsClass>
	inline void PhysicsShape<ShapeClass, BoundsClass>::setCenter(Vector2f center)
	{
		bounds.setPosition(center);
		shape.setCenter(center);
	}
	template<class ShapeClass, class BoundsClass>
	inline void PhysicsShape<ShapeClass, BoundsClass>::setSize(Vector2f size)
	{
		bounds.setSize(size);
		shape.setSize(size);
	}
	template<class ShapeClass, class BoundsClass>
	inline Vector2f PhysicsShape<ShapeClass, BoundsClass>::getCenter()
	{
		return shape.getCenter();
	}
	template<class ShapeClass, class BoundsClass>
	inline Vector2f PhysicsShape<ShapeClass, BoundsClass>::getSize()
	{
		return shape.getSize();
	}

	template<class ShapeClass, class BoundsClass>
	inline void PhysicsShape<ShapeClass, BoundsClass>::collisionCallback(PhysicsBodyCollisionResult& result)
	{
		//nop
	}

	template<class ShapeClass, class BoundsClass>
	inline void PhysicsShape<ShapeClass, BoundsClass>::updateCallback(unsigned int deltaMs)
	{
		//nop
	}
	
}



