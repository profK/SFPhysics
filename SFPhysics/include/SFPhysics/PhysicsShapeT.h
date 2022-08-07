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
	class PhysicsShapeT : public PhysicsShape, public ShapeClass, 
		public PhysicsBodyT<BoundsClass>
	{
	
	public:
		PhysicsShapeT();
		PhysicsShapeT(const PhysicsShapeT<ShapeClass,BoundsClass>& other);
		PhysicsShapeT& operator == (PhysicsShapeT& other) {
			return this == &other;
		}
		
		virtual void setCenter(Vector2f center) override;
		virtual void setSize(Vector2f size) override;
		virtual Vector2f getCenter() override;
		virtual Vector2f getSize() override;
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
		PhysicsBodyT<BoundsClass>::getBounds().onMove = [this](Vector2f pos) {
			ShapeClass::setCenter(pos);
		};
		PhysicsBodyT<BoundsClass>::onCollision = [this](PhysicsBodyCollisionResult& result) {
			if (onCollision) {
				onCollision(result);
			}
		};
		PhysicsBodyT<BoundsClass>::onUpdate = [this](unsigned int deltaMS) {
			if (onUpdate) {
				onUpdate(deltaMS);
			}
		};
	}

	template<class ShapeClass, class BoundsClass>
	inline PhysicsShapeT<ShapeClass, BoundsClass>::PhysicsShapeT(
		const PhysicsShapeT < ShapeClass,BoundsClass> &other): 
			ShapeClass(other),
			PhysicsBodyT<BoundsClass>(other)
	{
		
		PhysicsBodyT<BoundsClass>::getBounds().onMove = [this](Vector2f pos) {
			ShapeClass::setCenter(pos);
		};
		PhysicsBodyT<BoundsClass>::onCollision = [this](PhysicsBodyCollisionResult& result) {
			if (onCollision) {
				onCollision(result);
			}
		};
		PhysicsBodyT<BoundsClass>::onUpdate = [this](unsigned int deltaMS) {
			if (onUpdate) {
				onUpdate(deltaMS);
			}
		};
	}
	
	
	template<class ShapeClass, class BoundsClass>
	inline void PhysicsShapeT<ShapeClass, BoundsClass>::setCenter(Vector2f center)
	{
		PhysicsBodyT<BoundsClass>::setPosition(center);
		ShapeClass::setCenter(center);
	}
	template<class ShapeClass, class BoundsClass>
	inline void PhysicsShapeT<ShapeClass, BoundsClass>::setSize(Vector2f size)
	{
		PhysicsBodyT<BoundsClass>::getBounds().setSize(size);
		ShapeClass::setSize(size);
	}
	template<class ShapeClass, class BoundsClass>
	inline Vector2f PhysicsShapeT<ShapeClass, BoundsClass>::getCenter()
	{
		return ShapeClass::getCenter();
	}
	template<class ShapeClass, class BoundsClass>
	inline Vector2f PhysicsShapeT<ShapeClass, BoundsClass>::getSize()
	{
		return ShapeClass::getSize();
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



