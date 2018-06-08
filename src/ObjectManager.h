#pragma once

#include "Misc.h"
#include "Object.h"

class ObjectManager {
private:
	Screen*				_screen;
	std::list<Object*>	_listObj;
public:
	ObjectManager(Screen* screen) : _screen(screen) {}
	~ObjectManager();

	void	drawAll();
	Object* create(std::string fileName, int x, int y);
	void	erase(Object*);
	bool	isImpact(Object*);
};

