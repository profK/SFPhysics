#pragma once
#include <SFML/Graphics.hpp>
#include "PhysicsBodyT.h"
#include "CenteredShape.h"
#include "Bounds.h"
#include <functional>
#include "PhysicsShape.h"

using namespace sf;

namespace sfp {

	template <class ShapeClass, class BoundsClass>
	class PhysicsShapeT : PhysicsShape
	{
	protected:
		PhysicsBodyT<BoundsClass> body;
		ShapeClass shape;

	public:
		PhysicsShapeT();
		PhysicsShapeT(const PhysicsShapeT<ShapeClass,BoundsClass>& other);
		PhysicsShapeT& operator == (PhysicsShapeT& other) {
			return this == &other;
		}
		PhysicsBody& getBody() {
			return dynamic_cast<PhysicsBody&>(body);
		}
		CenteredShape& getShape() {
			return dynamic_cast<CenteredShape&>(shape);
		}
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
	inline PhysicsShapeT<ShapeClass, BoundsClass>::PhysicsShapeT()
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
	inline PhysicsShapeT<ShapeClass, BoundsClass>::PhysicsShapeT(const PhysicsShapeT < ShapeClass,
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
	inline void PhysicsShapeT<ShapeClass, BoundsClass>::setCenter(Vector2f center)
	{
		body.getBounds().setPosition(center);
		shape.setCenter(center);
	}
	template<class ShapeClass, class BoundsClass>
	inline void PhysicsShapeT<ShapeClass, BoundsClass>::setSize(Vector2f size)
	{
		body.getBounds().setSize(size);
		shape.setSize(size);
	}
	template<class ShapeClass, class BoundsClass>
	inline Vector2f PhysicsShapeT<ShapeClass, BoundsClass>::getCenter()
	{
		return shape.getCenter();
	}
	template<class ShapeClass, class BoundsClass>
	inline Vector2f PhysicsShapeT<ShapeClass, BoundsClass>::getSize()
	{
		return shape.getSize();
	}

	template<class ShapeClass, class BoundsClass>
	inline void PhysicsShapeT<ShapeClass, BoundsClass>::collisionCallback(PhysicsBodyCollisionResult& result)
	{
		//nop
	}

	template<class ShapeClass, class BoundsClass>
	inline void PhysicsShapeT<ShapeClass, BoundsClass>::updateCallback(unsigned int deltaMs)
	{
		//nop
	}
	
}



