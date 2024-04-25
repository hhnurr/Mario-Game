#include "Game.h"


Game::Game(int speed)
{
	///*
	sf::Font font;
	if (!font.loadFromFile("../assets/font.ttf"))
	{
		// error...
	}
	scoretext.setFont(font);
	score = 0;
	//*/

	
	marioHeadtexture.loadFromFile("../assets/mario7.png");
	for (int i = 0; i < 3; i++)
	{
		marioHeadSprite.setTexture(marioHeadtexture);

	}
	forturtles = 0;
	this-> speed = speed;
	window = new RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Mario");

	floorTexture.loadFromFile("../assets/floor.png");
	floorSprite.setTexture(floorTexture);
	floorSprite.scale(1.5f, 1);
	floorSprite.setPosition(0, WINDOW_HEIGHT-62);

	pipeTexture.loadFromFile("../assets/pipe.png");
	pipeSprite.setTexture(pipeTexture);
	pipeSprite.setPosition(WINDOW_WIDTH-130, WINDOW_HEIGHT - 62-74-5);
	
	pipe1Sprite.setTexture(pipeTexture);
	pipe1Sprite.scale(-1.f, 1.f);//simetrik alma
	pipe1Sprite.setPosition(130 ,WINDOW_HEIGHT - 62 - 74 - 5);


	brickTexture.loadFromFile("../assets/brick.png");
	for (int i = 0; i < 15; i++)
	{
		brickSprite[i].setTexture(brickTexture);
		brickSprite[i].setPosition(0+30*i, WINDOW_HEIGHT - 62 - 74 - 5 - 100);
	}

	for (int i = 15; i < 30; i++)
	{
		brickSprite[i].setTexture(brickTexture);
		brickSprite[i].setPosition(1400 - 30 * (i-15), WINDOW_HEIGHT - 62 - 74 - 5 - 100);
	}

	for (int i = 30; i < 50; i++)
	{
		brickSprite[i].setTexture(brickTexture);
		brickSprite[i].setPosition( 400+ 30 * (i - 30), WINDOW_HEIGHT - 62 - 74 - 5 - 100-225);
	}

	for (int i = 50; i < 65; i++)
	{
		brickSprite[i].setTexture(brickTexture);
		brickSprite[i].setPosition(0 + 30 * (i-50), WINDOW_HEIGHT - 62 - 74 - 5 - 550);
	}

	for (int i = 65; i < 80; i++)
	{
		brickSprite[i].setTexture(brickTexture);
		brickSprite[i].setPosition(1400 - 30 * (i - 65), WINDOW_HEIGHT - 62 - 74 - 5 - 550);
	}

	for (int i = 80; i < 84; i++)
	{
		brickSprite[i].setTexture(brickTexture);
		brickSprite[i].setPosition(1400 - 30 * (i - 80), WINDOW_HEIGHT - 62 - 74 - 5 - 240);
	}

	for (int i = 84; i < 88; i++)
	{
		brickSprite[i].setTexture(brickTexture);
		brickSprite[i].setPosition(0 + 30 * (i - 84), WINDOW_HEIGHT - 62 - 74 - 5 - 240);
	}

	spipeTexture.loadFromFile("../assets/pipeS.png");
	spipeSprite.setTexture(spipeTexture);
	spipeSprite.setPosition(WINDOW_WIDTH - 130, WINDOW_HEIGHT - 62 - 74 - 5-660);

	spipe1Sprite.setTexture(spipeTexture);
	spipe1Sprite.scale(-1.f, 1.f);//simetrik alma
	spipe1Sprite.setPosition(130, WINDOW_HEIGHT - 62 - 74 - 5-660);

}


void Game::update(void)
{
	while (window->isOpen())
	{
		int mariobricktouch;
		for (int i = 1; i < 87; i++)
		{
			int mariobricktouch1 = mario.collisionwith(brickSprite[i-1].getGlobalBounds());
			int mariobricktouch2 = mario.collisionwith(brickSprite[i].getGlobalBounds());
			int mariobricktouch3 = mario.collisionwith(brickSprite[i + 1].getGlobalBounds());

			if (mariobricktouch1 == 1 || mariobricktouch2 == 1 || mariobricktouch3 == 1)
			{
				mariobricktouch = 1;
				break;
			}

			else if (mariobricktouch1 == 2 || mariobricktouch2 == 2 || mariobricktouch3 == 2)
			{
				mariobricktouch = 2;
				break;
			}

			else if (mariobricktouch1 == 3 || mariobricktouch2 == 3 || mariobricktouch3 == 3)
			{
				mariobricktouch = 3;
				break;
			}
			else mariobricktouch = 0;
		}
		
		int mariofloortouch= mario.collisionwith(floorSprite.getGlobalBounds());
		int mariogeneral;
		if (mariofloortouch == 0) mariogeneral = mariobricktouch;
		else mariogeneral = 1;




		for (int j = 0; j < 5; j++)
		{
			int turtlebricktouch;
			for (int i = 0; i < 88; i++)
			{
				turtlebricktouch = turtle[j].collisionwith(brickSprite[i].getGlobalBounds());
				if (turtlebricktouch != 0) break;
			}

			int turtlefloortouch = turtle[j].collisionwith(floorSprite.getGlobalBounds());
			int turtlegeneral;
			if (turtlefloortouch == 0) turtlegeneral = turtlebricktouch;
			else turtlegeneral = 1;
			turtle[j].verticalMove(turtlegeneral);
		}



		
		mario.verticalMove(mariogeneral);

		Event event;
		while (window->pollEvent(event))
		{
			if (event.type == Event::Closed)
				window->close();
			else if (event.type == Event::KeyPressed)
			{
				if (Keyboard::isKeyPressed(Keyboard::Up) && mariogeneral==1)
					mario.jump();
				else if (event.key.code == Keyboard::Right)
				{

					rightisPressed = 1;
					leftisPressed = 0;
				}

				else if (event.key.code == Keyboard::Left)
				{
					leftisPressed = 1;
					rightisPressed = 0;
				}
				if (event.key.code == Keyboard::Escape)
					window->close();
			}
			else 
			{
				leftisPressed = 0;
				rightisPressed = 0;
			}
		}


		if (leftisPressed == 1)
			mario.walk(Mario::WalkDirection::Left);
		else if (rightisPressed == 1)
			mario.walk(Mario::WalkDirection::Right);
		else mario.walk(Mario::WalkDirection::NONE);

		for (int i = 0; i < 5; i++)
		{
			turtle[i].walk();
		}


		for (int i = 0; i < 5; i++)
		{
			if (mario.collisionwith(turtle[i].getSpriteBoundary()) == 1 && !mario.getDead() && !turtle[i].getDead())
			{
				turtle[i].jump();
				turtle[i].makeDead();
				for (int j = 0; j < 5; j++)
				{
					turtle[j].fastenturtle();
				}
				score += 100;
			}
			else if (mario.collisionwith(turtle[i].getSpriteBoundary()) == 3 && !turtle[i].getDead() && !mario.getDead())
			{
				mario.jump();
				mario.makeDead();
			}
		}

		if (forturtles == 100 || forturtles == 200 || forturtles == 300 || forturtles == 400 || forturtles == 0)
		{
			turtle[forturtles/100].makeAlive();
		}

		cout << forturtles << endl;
		window->clear();

		

		for (int i = 0; i < 88; i++)
		{
			window->draw(brickSprite[i]);
		}

		mario.draw(window);

		
		for (int i = 0; i < 5; i++)
		{
			turtle[i].draw(window);
		}
		
		window->draw(floorSprite);
		window->draw(pipeSprite);
		window->draw(pipe1Sprite);
		window->draw(spipeSprite);
		window->draw(spipe1Sprite);


		for (int i = 0; i < mario.getLife(); i++)
		{
			
			marioHeadSprite.setPosition(WINDOW_WIDTH - marioHeadSprite.getGlobalBounds().width * (i + 1), 0);
			window->draw(marioHeadSprite);
		}

		//sprintf(str, "%d", score);
		scoretext.setString("aa");
		//scoretext.setCharacterSize(24); 
		scoretext.setFillColor(sf::Color::Red);
		scoretext.setStyle(sf::Text::Bold | sf::Text::Underlined);
		scoretext.setPosition(0, 0);
	    //window->draw(scoretext);
//*/
		window->display();

		if (forturtles<1000) forturtles++;
		sf::sleep(sf::milliseconds(1000 /40));
	}
	
}

