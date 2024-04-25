#include "Common.h"
#include "Mario.h"
#include "Turtle.h"
#include "Object.h"

class Game
{
	RenderWindow* window;
	Texture floorTexture;
	Sprite floorSprite;
	Texture pipeTexture;
	Sprite pipeSprite;
	Sprite pipe1Sprite;
	Texture brickTexture;
	Sprite brickSprite[100];
	Texture spipeTexture;
	Sprite spipeSprite;
	Sprite spipe1Sprite;
	Sprite marioHeadSprite;
	Texture marioHeadtexture;
	//Text createtext(Fon)
	bool leftisPressed = 0;
	bool rightisPressed = 0;
	int forturtles;
	int score;
	Text scoretext;
	Font font;
	String str[10];

	Mario mario;
	Turtle turtle[5];

	int speed;
public:
	
	Game(int);
	void update(void);
};