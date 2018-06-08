#pragma once

#include "Misc.h"

class Border {
private:
	int* _dataX;
	int* _dataY;
	int  _x;
	int  _y;
	int	 _size;
public:
	Border() {}
	Border(std::string fileName, int x = 0, int y = 0);
	~Border();

	void setX(int x) { _x = x; }
	void setY(int y) { _y = y; }
	int  getX() { return _x; }
	int  getY() { return _y; }

	bool isImpact(Border&);
};

