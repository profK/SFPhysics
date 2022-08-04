#pragma once
#include <SFML/Graphics.hpp>
#include "PhysicsBodyT.h"
#include "CenteredShape.h"
#include "Bounds.h"
#include <functional>

using namespace sf;

namespace sfp {

	template <class ShapeClass, class BoundsClass>
	class PhysicsShape
	{
	protected:
		PhysicsBodyT<BoundsClass> body;
		ShapeClass shape;

	public:
		PhysicsShape();
		PhysicsShape(const PhysicsShape<ShapeClass,BoundsClass>& other);
		PhysicsShape& operator == (PhysicsShape& other) {
			return this == &other;
		}
		PhysicsBody& getBody();
		ShapeClass& getShape();
		void setCenter(Vector2f center);
		void setSize(Vector2f size);
		Vector2f getCenter();
		Vector2f getSize();
		function<void(PhysicsBodyCollisionResult&)> onCollision = [this]
			(PhysicsBodyCollisionResult& result) {
				this->collisionCallback(result);
			};
		function<void(unsigned int)> onUpdate = [this]
			(unsigned int deltaMS) {
				this->updateCallback(deltaMS);
			};
		virtual void collisionCallback(
			PhysicsBodyCollisionResult& result);
		virtual void updateCallback(unsigned int deltaMs);
	};

	template<class ShapeClass, class BoundsClass>
	inline PhysicsShape<ShapeClass, BoundsClass>::PhysicsShape()
	{
		//static_assert(std::is_base_of<CenteredShape, ShapeClass>::value, 
		//	"type parameter of this class must derive from CenteredShape");
		//static_assert(std::is_base_of<BoundsClass, Bounds>::value,
		//	"type parameter of this class must derive from Bounds");

		body.getBounds().onMove = [this](Vector2f pos) {
			this->getShape().setCenter(pos);
		};
		body.onCollision = [this](PhysicsBodyCollisionResult& result) {
			if (onCollision) {
				onCollision(result);
			}
		};
		body.onUpdate = [this](unsigned int deltaMS) {
			if (onUpdate) {
				onUpdate(deltaMS);
			}
		};
	}

	template<class ShapeClass, class BoundsClass>
	inline PhysicsShape<ShapeClass, BoundsClass>::PhysicsShape(const PhysicsShape < ShapeClass,
		BoundsClass> &other)
	{
		body = other.body;
		shape = other.shape;
		body.getBounds().onMove = [this](Vector2f pos) {
			this->getShape().setCenter(pos);
		};
		body.onCollision = [this](PhysicsBodyCollisionResult& result) {
			if (onCollision) {
				onCollision(result);
			}
		};
		body.onUpdate = [this](unsigned int deltaMS) {
			if (onUpdate) {
				onUpdate(deltaMS);
			}
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
		body.getBounds().setPosition(center);
		shape.setCenter(center);
	}
	template<class ShapeClass, class BoundsClass>
	inline void PhysicsShape<ShapeClass, BoundsClass>::setSize(Vector2f size)
	{
		body.getBounds().setSize(size);
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



