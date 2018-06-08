#pragma once

#include "Misc.h"
#include "Screen.h"
#include "ObjectManager.h"

class Game {
private:
	bool			_running;
	Screen			_screen;
	ObjectManager	_objman;
	Object*			_manchar;
	Object**		_enemies;
	int				_countEnemies;

	int				_key;
public:
	Game();
	~Game();

	void check();
	void move();
	void moveE();

	void loop();
	void gexit();
};

