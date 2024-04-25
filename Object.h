#pragma once
#include "Common.h"

//#include "Turtle.h"

class Object {
	Vector2f pos;
	int state;
protected:
	int life;
	bool dead;
	Texture textures[8];
	bool changedirection;
	int verticalSpeed;
	int horizontalSpeed;
	Sprite sprite;
	bool initial;
	
public:
	enum WalkDirection {
		Left,
		Right,
		NONE
	};
	Vector2f getPosition(); 
	FloatRect getSpriteBoundary();
	int getLife();
	void makeAlive();
	void makeDead();
	bool getDead();
	void setPosition(Vector2f);
	void draw(RenderWindow* window);
	void jump();
	int collisionwith(FloatRect);
	void verticalMove(int);

};

