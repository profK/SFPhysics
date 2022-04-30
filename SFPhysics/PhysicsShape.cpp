#include "pch.h"
#include "PhysicsShape.h"
#include "Bounds.h"
#include "CenteredShape.h"


using namespace sfp;

template <class ShapeClass, class BoundsClass>
sfp::PhysicsShape<ShapeClass, BoundsClass>::PhysicsShape():
	defaultBounds(),body(defaultBounds),shape()
{
	static_assert(std::is_base_of<Bounds,BoundsClass>::value, 
		"type parameter of this class must derive from Bounds");
	static_assert(std::is_base_of<CenteredShape, ShapeClass>::value,
		"type parameter of this class must derive from CenteredShape");
	body.getBounds().onMove = [this](Vector2f center) {
		shape.setCenter(center);
	};

}

template <class ShapeClass, class BoundsClass>
PhysicsBody sfp::PhysicsShape<ShapeClass, BoundsClass>::getBody() {
	return body;
}

template <class ShapeClass, class BoundsClass>
ShapeClass sfp::PhysicsShape<ShapeClass, BoundsClass>::getShape() {
	return shape;
}

template<class ShapeClass, class BoundsClass>
void sfp::PhysicsShape<ShapeClass, BoundsClass>::setCenter(Vector2f center)
{
    shape.setCenter(center);
	body.getBounds().setCenter(center);
}

template<class ShapeClass, class BoundsClass>
void sfp::PhysicsShape<ShapeClass, BoundsClass>::setSize(Vector2f size)
{
	body.getBounds().setSize(size);
	shape.setSize(size);
}

template<class ShapeClass, class BoundsClass>
Vector2f sfp::PhysicsShape<ShapeClass, BoundsClass>::getCenter()
{
	return getShape().getCenter();
}

template<class ShapeClass, class BoundsClass>
Vector2f sfp::PhysicsShape<ShapeClass, BoundsClass>::getSize()
{
	return getShape().getSize();
}


