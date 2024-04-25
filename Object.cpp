
#include "Object.h"
#include <math.h>

Vector2f Object::getPosition()
{
	return sprite.getPosition();
}

void Object::setPosition(Vector2f pos)
{
	this->pos = pos;
	sprite.setPosition(pos);
}

void Object::draw(RenderWindow* window)
{
	window->draw(sprite);
}

void Object::makeDead()
{
    dead = 1;
    life = life - 1;
}

void Object::makeAlive()
{
    dead = 0;
    sprite.setPosition(5, /*WINDOW_HEIGHT */ +100);

}

void Object::jump()
{
    verticalSpeed = -30;
    sprite.move(0, verticalSpeed);
}



bool Object::getDead()
{
    return dead;
}

int Object::getLife()
{
    return life;
}

void Object::verticalMove(int ground) 
{
    if(dead==0)
    {
        if (ground == 1) verticalSpeed = 0;
        else if (ground == 2 || ground == 3)
        {
            if (verticalSpeed < 0)
            {
                verticalSpeed = -verticalSpeed;
            }
        }
        else if (ground == 0)
        {
            if (verticalSpeed < 13)
                verticalSpeed += 2;
        }
        sprite.move(0, verticalSpeed);
        if (sprite.getPosition().y + sprite.getGlobalBounds().height > WINDOW_HEIGHT - 62)
        {
            sprite.setPosition(sprite.getPosition().x, WINDOW_HEIGHT - 62 - sprite.getGlobalBounds().height + 5);
        }
    }
    else
    {
        if (verticalSpeed < 13)
            verticalSpeed += 2;
        sprite.move(0, verticalSpeed);
        if (life > 0 && sprite.getPosition().y >= 900)
        {
            sprite.setPosition(700, 100/*WINDOW_HEIGHT - 62 - sprite.getGlobalBounds().height + 5*/);
            dead = 0;
        }
    }
}

FloatRect Object::getSpriteBoundary()
{
    FloatRect spriteBound = sprite.getGlobalBounds();
    return spriteBound;
}

int Object::collisionwith(FloatRect otherSpriteBound)
{
    FloatRect spriteBound = sprite.getGlobalBounds();


    if (spriteBound.intersects(otherSpriteBound))
    {
        float spritetop = spriteBound.top;
        float spritecenterx = spriteBound.left + spriteBound.width / 2;
        float otherSpriteTop = otherSpriteBound.top;
        float otherspriteleft = otherSpriteBound.left;
        float otherspritecentery = otherSpriteBound.top + otherSpriteBound.height / 2;
        if (otherspritecentery > spritetop && otherspritecentery < spritetop + spriteBound.width) return 3;

        else if (spritetop > otherSpriteTop)
        {
            if (spriteBound.width > otherSpriteBound.width)
            {
                if (spritecenterx<otherspriteleft + spriteBound.width && spritecenterx > otherspriteleft) return 2;
                else return 3;
            }
            else
            {
                if (spritecenterx<otherspriteleft + otherSpriteBound.width && spritecenterx > otherspriteleft) return 2;
                else return 3;
            }
        }
        else return 1;
    }
    else return 0; //bu son olsun amk

}





