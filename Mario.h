#include "Common.h"
#include "Object.h"

class Mario:public Object {
	int state;
	int lastheading;
public:
	enum WalkDirection {
		Left,
		Right,
		NONE
	};
	
	Mario();
	void walk(WalkDirection dir);
	void setPosition(Vector2f);
};