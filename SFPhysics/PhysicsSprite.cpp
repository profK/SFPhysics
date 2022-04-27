#include "pch.h"
#include "PhysicsSprite.h"

sfp::PhysicsSprite::PhysicsSprite():
	defaultBounds(),CenteredSprite(),
	PhysicsBody(defaultBounds)
{
	getBounds().onMove = [this](Vector2f center) {
		CenteredSprite::setCenter(center);
	};
}

sfp::PhysicsSprite::PhysicsSprite(Texture& tex, bool isStatic):
	defaultBounds(
		Vector2f(0,0),
		Vector2f(tex.getSize().x,tex.getSize().y)),
	CenteredSprite(), PhysicsBody(defaultBounds)
{
	getBounds().onMove = [this](Vector2f center) {
		CenteredSprite::setCenter(center);
	};
}

void sfp::PhysicsSprite::setImage(Texture& img)
{
	CenteredSprite::setImage(img);

}

void sfp::PhysicsSprite::setCenter(Vector2f center)
{
	CenteredSprite::setCenter(center);
	PhysicsBody::setPosition(center);
}
