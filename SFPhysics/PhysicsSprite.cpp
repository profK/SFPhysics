#include "pch.h"
#include "PhysicsSprite.h"

void sfp::PhysicsSprite::setTexture(Texture& img)
{
	CenteredSprite::setTexture(img);
	IntRect sz = CenteredSprite::getTextureRect();
	PhysicsBodyT<AABB>::getBounds().setSize(Vector2f(sz.width, sz.height));
	setCenter(CenteredSprite::getCenter());
}
