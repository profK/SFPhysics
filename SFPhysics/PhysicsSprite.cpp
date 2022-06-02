#include "pch.h"
#include "PhysicsSprite.h"

void sfp::PhysicsSprite::setTexture(Texture& img)
{
	shape.setTexture(img);
	IntRect sz = shape.getTextureRect();
	bounds.setSize(Vector2f(sz.width, sz.height));
	setCenter(shape.getCenter());
}
