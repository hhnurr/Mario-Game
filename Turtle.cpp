#include "Turtle.h"


Turtle::Turtle()
{
	initial = 0;
	changedirection = 0;
	life = 1;
	char path[64];
	horizontalSpeed = 5;
	//textures[0].loadFromFile("../assets/turtle0.png");
	for (int i = 1; i < 6; i++)
	{
		sprintf(path, "../assets/turtle%d.png", i);
		textures[i].loadFromFile(path);
	}
	dead = 0;
	state = 1;
	sprite.setTexture(textures[state]);
	//sprite.setPosition(5, /*WINDOW_HEIGHT */ +100);
	sprite.setOrigin(33, 0);
}

void Turtle::fastenturtle()
{
	horizontalSpeed = horizontalSpeed + 4;
}

void Turtle::walk()
{
	if (!dead)
	{
		switch (state) {
		case 1:
		{
			if (sprite.getPosition().x < 1400)
			{

				state = 2;
				sprite.move(Vector2f(horizontalSpeed, 0));
				changedirection = 0;

			}
			else
			{
				if (sprite.getPosition().y == WINDOW_HEIGHT - 62 - sprite.getGlobalBounds().height + 5)
				{
					sprite.setPosition(5, WINDOW_HEIGHT - 62 - 74 - 5 - 660);
					sprite.move(Vector2f(horizontalSpeed, 0));
					changedirection = 0;
					state = 2;
				}
				else
				{
					sprite.move(Vector2f(-horizontalSpeed, 0));
					sprite.setPosition(1400, sprite.getPosition().y);
					state = 5;
					changedirection = 1;
				}
			}
			break;

		}
		case 2:
		{
			if (sprite.getPosition().x < 1400)
			{

				state = 3;
				sprite.move(Vector2f(horizontalSpeed, 0));
				changedirection = 0;

			}
			else
			{
				if (sprite.getPosition().y == WINDOW_HEIGHT - 62 - sprite.getGlobalBounds().height + 5)
				{
					sprite.setPosition(5, WINDOW_HEIGHT - 62 - 74 - 5 - 660);
					sprite.move(Vector2f(horizontalSpeed, 0));
					changedirection = 0;
					state = 3;
				}
				else
				{
					sprite.move(Vector2f(-horizontalSpeed, 0));
					sprite.setPosition(1400, sprite.getPosition().y);
					state = 5;
					changedirection = 1;
				}
			}
			break;
		}
		case 3:
		{
			if (sprite.getPosition().x < 1400)
			{

				state = 4;
				sprite.move(Vector2f(horizontalSpeed, 0));
				changedirection = 0;

			}
			else
			{
				if (sprite.getPosition().y == WINDOW_HEIGHT - 62 - sprite.getGlobalBounds().height + 5)
				{
					sprite.setPosition(5, WINDOW_HEIGHT - 62 - 74 - 5 - 660);
					sprite.move(Vector2f(horizontalSpeed, 0));
					changedirection = 0;
					state = 4;
				}
				else
				{
					sprite.move(Vector2f(-horizontalSpeed, 0));
					sprite.setPosition(1400, sprite.getPosition().y);
					state = 5;
					changedirection = 1;
				}
			}
			break;

		}
		case 4:
		{
			if (sprite.getPosition().x < 1400)
			{

				state = 1;
				sprite.move(Vector2f(horizontalSpeed, 0));
				changedirection = 0;

			}
			else
			{
				if (sprite.getPosition().y == WINDOW_HEIGHT - 62 - sprite.getGlobalBounds().height + 5)
				{
					sprite.setPosition(5, WINDOW_HEIGHT - 62 - 74 - 5 - 660);
					sprite.move(Vector2f(horizontalSpeed, 0));
					changedirection = 0;
					state = 2;
				}
				else
				{
					sprite.move(Vector2f(-horizontalSpeed, 0));
					sprite.setPosition(1400, sprite.getPosition().y);
					state = 5;
					changedirection = 1;
				}
			}
			break;
		}
		case 5:
		{
			if (sprite.getPosition().x > 0)
			{

				state = 6;
				sprite.move(Vector2f(-horizontalSpeed, 0));
				changedirection = 0;

			}
			else
			{
				if (sprite.getPosition().y == WINDOW_HEIGHT - 62 - sprite.getGlobalBounds().height + 5)
				{
					sprite.setPosition(1395, WINDOW_HEIGHT - 62 - 74 - 5 - 660);
					sprite.move(Vector2f(-horizontalSpeed, 0));
					changedirection = 0;
					state = 6;
				}
				else
				{
					sprite.move(Vector2f(horizontalSpeed, 0));
					sprite.setPosition(5, sprite.getPosition().y);
					state = 1;
					changedirection = 1;
				}
			}
			break;

		}
		case 6:
		{
			if (sprite.getPosition().x > 0)
			{

				state = 7;
				sprite.move(Vector2f(-horizontalSpeed, 0));
				changedirection = 0;

			}
			else
			{
				if (sprite.getPosition().y == WINDOW_HEIGHT - 62 - sprite.getGlobalBounds().height + 5)
				{
					sprite.setPosition(1395, WINDOW_HEIGHT - 62 - 74 - 5 - 660);
					sprite.move(Vector2f(-horizontalSpeed, 0));
					changedirection = 0;
					state = 7;
				}
				else
				{
					sprite.move(Vector2f(horizontalSpeed, 0));
					sprite.setPosition(5, sprite.getPosition().y);
					state = 1;
					changedirection = 1;
				}
			}
			break;

		}
		case 7:
		{
			if (sprite.getPosition().x > 0)
			{

				state = 8;
				sprite.move(Vector2f(-horizontalSpeed, 0));
				changedirection = 0;

			}
			else
			{
				if (sprite.getPosition().y == WINDOW_HEIGHT - 62 - sprite.getGlobalBounds().height + 5)
				{
					sprite.setPosition(1395, WINDOW_HEIGHT - 62 - 74 - 5 - 660);
					sprite.move(Vector2f(-horizontalSpeed, 0));
					changedirection = 0;
					state = 8;
				}
				else
				{
					sprite.move(Vector2f(horizontalSpeed, 0));
					sprite.setPosition(5, sprite.getPosition().y);
					state = 1;
					changedirection = 1;
				}
			}
			break;

		}
		case 8:
		{
			if (sprite.getPosition().x > 0)
			{

				state = 5;
				sprite.move(Vector2f(-horizontalSpeed, 0));
				changedirection = 0;

			}
			else
			{
				if (sprite.getPosition().y == WINDOW_HEIGHT - 62 - sprite.getGlobalBounds().height + 5)
				{
					sprite.setPosition(1395, WINDOW_HEIGHT - 62 - 74 - 5 - 660);
					sprite.move(Vector2f(-horizontalSpeed, 0));
					changedirection = 0;
					state = 5;
				}
				else
				{
					sprite.move(Vector2f(horizontalSpeed, 0));
					sprite.setPosition(5, sprite.getPosition().y);
					state = 1;
					changedirection = 1;
				}
			}
			break;
		}
		}

		sprite.setOrigin(34, 0);
		//if (state == 0) sprite.setTexture(textures[0]);
		if (state > 0 && state < 4) sprite.setTexture(textures[state]);
		else if (state == 4) sprite.setTexture(textures[2]);
		else if (state == 8) sprite.setTexture(textures[2]);
		else if (state > 4 && state < 8) sprite.setTexture(textures[state - 4]);


		if (changedirection)
		{
			sprite.scale(-1.f, 1.f);
		}
	}
	else
	{
	sprite.setTexture(textures[5]);
	}
}