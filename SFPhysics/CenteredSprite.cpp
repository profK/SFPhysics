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
    Vector2f sz = getSize();
    setPosition(Vector2f(center.x - (sz.x / 2), center.y - (sz.y / 2)));
}

Vector2f CenteredSprite::getCenter()
{
    Vector2f szvect = getSize();
    Vector2f pos = getPosition();
    return Vector2f(pos + (szvect / 2.0f));
}

void sfp::CenteredSprite::setSize(Vector2f size)
{
    IntRect imageSize = getTextureRect();
    Vector2f scale = 
        Vector2f(size.x/imageSize.width,size.y/imageSize.height);
    Sprite::setScale(scale);
}

Vector2f sfp::CenteredSprite::getSize()
{
    IntRect imageSize = getTextureRect();
    Vector2f scale = getScale();
    return Vector2f(imageSize.width*scale.x,
        imageSize.height*scale.y);
}


