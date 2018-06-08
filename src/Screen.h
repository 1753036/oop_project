#pragma once

#include "Misc.h"

class Screen {
private:
	char**	_colors;
	int		_width;
	int		_height;
	int		_x;
	int		_y;
public:
	Screen(int x, int y, int w, int h);
	~Screen();
	int getX() { return _x; }
	int getY() { return _y; }
	int getW() { return _width; }
	int getH() { return _height; }
	void present();
	void clear();
	void replace(int x, int y, int color);
};

