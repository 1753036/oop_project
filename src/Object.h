#pragma once

#include "Texture.h"
#include "Border.h"

class Object {
private:
	Texture  _texture;
	Border	 _border;
	int		 _x;
	int		 _y;
public:
	Object(Screen* screen, std::string fileName, int x = 0, int y = 0);

	int  getX() { return _x; }
	int  getY() { return _y; }
	void setX(int x) { _x = x; _border.setX(_x); }
	void setY(int y) { _y = y; _border.setY(_y); }

	void setLoc(int x, int y);
	void draw();

	bool isImpact(Object& obj);
};