#include "Mario.h"


Mario::Mario() 
{
	initial = 1;
	life = 3;
	verticalSpeed = 10;
	changedirection = 0;
	lastheading = 1;
	char path[64];
	textures[0].loadFromFile("../assets/mario0.png");
	for (int i = 1; i < 8; i++)
	{
		sprintf(path, "../assets/mario%d.png", i);
		textures[i].loadFromFile(path);
	}
	dead = 0;
	state = 0;
	sprite.setTexture(textures[state]);
	sprite.setPosition(700, WINDOW_HEIGHT -100 );
	sprite.setOrigin(33, 0);
}

void Mario::setPosition(Vector2f pos)
{
	sprite.setPosition(pos);
}


void Mario::walk(WalkDirection dir)
{
	if (!dead)
	{
		switch (state) {
		case 0:
			if (dir == WalkDirection::Left)
			{
				state = 1;
				sprite.move(Vector2f(-SPEED, 0));

				if (sprite.getPosition().x > 1400) sprite.setPosition(1400, sprite.getPosition().y);
				else if (sprite.getPosition().x < 0) sprite.setPosition(5, sprite.getPosition().y);
				if (!lastheading) sprite.scale(-1.f, 1.f);
			}
			else if (dir == WalkDirection::Right)
			{
				sprite.move(Vector2f(SPEED, 0));

				if (sprite.getPosition().x > 1400) sprite.setPosition(1400, sprite.getPosition().y);
				else if (sprite.getPosition().x < 0) sprite.setPosition(5, sprite.getPosition().y);
				state = 5;
				if(lastheading) sprite.scale(-1.f, 1.f);
			}
			break;
		case 1:
		{
			if (dir == WalkDirection::Left)
			{

				state = 2;
				sprite.move(Vector2f(-SPEED, 0));

				if (sprite.getPosition().x > 1400) sprite.setPosition(1400, sprite.getPosition().y);
				else if (sprite.getPosition().x < 0) sprite.setPosition(5, sprite.getPosition().y);
				changedirection = 0;

			}
			else if (dir == WalkDirection::Right)
			{
				sprite.move(Vector2f(SPEED, 0));

				if (sprite.getPosition().x > 1400) sprite.setPosition(1400, sprite.getPosition().y);
				else if (sprite.getPosition().x < 0) sprite.setPosition(5, sprite.getPosition().y);
				state = 5;
				changedirection = 0;
			}
			else if (dir == WalkDirection::NONE)
			{
				state = 0;
				lastheading = 1;
			}
			break;

		}
		case 2:
		{
			if (dir == WalkDirection::Left)
			{
				sprite.move(Vector2f(-SPEED, 0));

				if (sprite.getPosition().x > 1400) sprite.setPosition(1400, sprite.getPosition().y);
				else if (sprite.getPosition().x < 0) sprite.setPosition(5, sprite.getPosition().y);
				state = 3;
				changedirection = 0;
			}
			else if (dir == WalkDirection::Right)
			{
				sprite.move(Vector2f(SPEED, 0));

				if (sprite.getPosition().x > 1400) sprite.setPosition(1400, sprite.getPosition().y);
				else if (sprite.getPosition().x < 0) sprite.setPosition(5, sprite.getPosition().y);
				state = 5;
				changedirection = 1;
			}
			else if (dir == WalkDirection::NONE)
			{
				state = 0;
				lastheading = 1;
			}
			break;

		}
		case 3:
		{
			if (dir == WalkDirection::Left)
			{
				sprite.move(Vector2f(-SPEED, 0));

				if (sprite.getPosition().x > 1400) sprite.setPosition(1400, sprite.getPosition().y);
				else if (sprite.getPosition().x < 0) sprite.setPosition(5, sprite.getPosition().y);
				state = 4;
				changedirection = 0;
			}
			else if (dir == WalkDirection::Right)
			{
				sprite.move(Vector2f(SPEED, 0));

				if (sprite.getPosition().x > 1400) sprite.setPosition(1400, sprite.getPosition().y);
				else if (sprite.getPosition().x < 0) sprite.setPosition(5, sprite.getPosition().y);
				state = 5;
				changedirection = 1;
			}
			else if (dir == WalkDirection::NONE)
			{
				state = 0;
				lastheading = 1;
			}
			break;

		}
		case 4:
		{
			if (dir == WalkDirection::Left)
			{
				sprite.move(Vector2f(-SPEED, 0));

				if (sprite.getPosition().x > 1400) sprite.setPosition(1400, sprite.getPosition().y);
				else if (sprite.getPosition().x < 0) sprite.setPosition(5, sprite.getPosition().y);
				state = 1;
				changedirection = 0;
			}
			else if (dir == WalkDirection::Right)
			{
				sprite.move(Vector2f(SPEED, 0));

				if (sprite.getPosition().x > 1400) sprite.setPosition(1400, sprite.getPosition().y);
				else if (sprite.getPosition().x < 0) sprite.setPosition(5, sprite.getPosition().y);
				state = 5;
				changedirection = 1;
			}
			else if (dir == WalkDirection::NONE)
			{
				state = 0;
				lastheading = 1;
			}
			break;
		}
		case 5:
		{
			if (dir == WalkDirection::Left)
			{

				state = 1;
				sprite.move(Vector2f(-SPEED, 0));

				if (sprite.getPosition().x > 1400) sprite.setPosition(1400, sprite.getPosition().y);
				else if (sprite.getPosition().x < 0) sprite.setPosition(5, sprite.getPosition().y);
				changedirection = 1;


			}
			else if (dir == WalkDirection::Right)
			{
				sprite.move(Vector2f(SPEED, 0));

				if (sprite.getPosition().x > 1400) sprite.setPosition(1400, sprite.getPosition().y);
				else if (sprite.getPosition().x < 0) sprite.setPosition(5, sprite.getPosition().y);
				state = 6;
				changedirection = 0;
			}
			else if (dir == WalkDirection::NONE)
			{
				state = 0;
				lastheading = 0;
			}
			break;

		}
		case 6:
		{
			if (dir == WalkDirection::Left)
			{
				sprite.move(Vector2f(-SPEED, 0));

				if (sprite.getPosition().x > 1400) sprite.setPosition(1400, sprite.getPosition().y);
				else if (sprite.getPosition().x < 0) sprite.setPosition(5, sprite.getPosition().y);
				state = 1;
				changedirection = 1;
			}
			else if (dir == WalkDirection::Right)
			{
				sprite.move(Vector2f(SPEED, 0));

				if (sprite.getPosition().x > 1400) sprite.setPosition(1400, sprite.getPosition().y);
				else if (sprite.getPosition().x < 0) sprite.setPosition(5, sprite.getPosition().y);
				state = 7;
				changedirection = 0;
			}
			else if (dir == WalkDirection::NONE)
			{
				state = 0;
				lastheading = 0;
			}
			break;

		}
		case 7:
		{
			if (dir == WalkDirection::Left)
			{
				sprite.move(Vector2f(-SPEED, 0));

				if (sprite.getPosition().x > 1400) sprite.setPosition(1400, sprite.getPosition().y);
				else if (sprite.getPosition().x < 0) sprite.setPosition(5, sprite.getPosition().y);
				state = 1;
				changedirection = 1;
			}
			else if (dir == WalkDirection::Right)
			{
				sprite.move(Vector2f(SPEED, 0));

				if (sprite.getPosition().x > 1400) sprite.setPosition(1400, sprite.getPosition().y);
				else if (sprite.getPosition().x < 0) sprite.setPosition(5, sprite.getPosition().y);
				state = 8;
				changedirection = 0;
			}
			else if (dir == WalkDirection::NONE)
			{
				state = 0;
				lastheading = 0;
			}
			break;

		}
		case 8:
		{
			if (dir == WalkDirection::Left)
			{
				sprite.move(Vector2f(-SPEED, 0));

				if (sprite.getPosition().x > 1400) sprite.setPosition(1400, sprite.getPosition().y);
				else if (sprite.getPosition().x < 0) sprite.setPosition(5, sprite.getPosition().y);
				state = 1;
				changedirection = 1;
			}
			else if (dir == WalkDirection::Right)
			{
				sprite.move(Vector2f(SPEED, 0));
				if (sprite.getPosition().x > 1400) sprite.setPosition(1400, sprite.getPosition().y);
				else if (sprite.getPosition().x < 0) sprite.setPosition(5, sprite.getPosition().y);
				state = 5;
				changedirection = 0;
			}
			else if (dir == WalkDirection::NONE)
			{
				state = 0;
				lastheading = 0;
			}
			break;
		}
		}

		sprite.setOrigin(33, 0);
		if (state == 0) sprite.setTexture(textures[0]);
		else if (state > 0 && state < 5) sprite.setTexture(textures[state]);
		else if (state == 4) sprite.setTexture(textures[2]);
		else if (state == 8) sprite.setTexture(textures[2]);
		else if (state > 4 && state < 8) sprite.setTexture(textures[state - 4]);


		if (changedirection)
		{
			sprite.scale(-1.f, 1.f);
			changedirection = 0;
		}
	}
	else
	{
	sprite.setTexture(textures[6]);
    }
}
