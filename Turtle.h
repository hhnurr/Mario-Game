#include "Common.h"
#include "Object.h"

class Turtle :public Object {
	int state;

public:
	Turtle();
	void walk();
	void fastenturtle();
};