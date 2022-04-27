#include "pch.h"
#include "CenteredSprite.h"

using namespace sfp;

sfp::CenteredSprite::CenteredSprite(): Sprite()
{
}

CenteredSprite::CenteredSprite(Texture& tex) :
    Sprite(tex)
{
}

void sfp::CenteredSprite::setImage(Texture& img)
{
    Vector2f center = getCenter();
    Sprite::setTexture(img);
    setCenter(center);
}

Texture& sfp::CenteredSprite::getImage()
{
    return getImage();
}


void CenteredSprite::setCenter(Vector2f center)
{
    IntRect sz = getTextureRect();
    setPosition(
        Vector2f(center.x - (sz.width / 2), center.y - (sz.height / 2)));
}

Vector2f CenteredSprite::getCenter()
{
    IntRect sz = getTextureRect();
    Vector2f szvect = Vector2f(sz.width, sz.height);
    Vector2f pos = getPosition();
    return Vector2f(pos + (szvect / 2.0f));
}
