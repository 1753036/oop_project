#include "Screen.h"

Screen::Screen(int x, int y, int w, int h)
	: _width(w)
	, _height(h) 
	, _x(x)
	, _y(y)
	, _colors(NULL)
{
	_colors = new char*[_height];
	for (int i = 0; i < _height; ++i) {
		_colors[i] = new char[_width];
		for (int j = 0; j < _width; ++j) {
			_colors[i][j] = 0;
		}
	}

	fixWindowConsole();
	showConsoleCursor(false);
}

Screen::~Screen() {
	for (int i = 0; i < _height; ++i)
		delete[] _colors[i];
	delete[] _colors;
}

void Screen::present() {
	int last = 0;

	for (int i = 0; i < _height; ++i) {
		moveCursor(_x, _y + i);
		for (int j = 0; j < _width; ++j) {
			if (_colors[i][j] != last) {
				setBgColor(_colors[i][j]);
				last = _colors[i][j];
			}
			// setBgColor(_colors[i][j]);
			fputc(' ', stdout);
		}
	}
}

void Screen::clear() {
	for (int i = 0; i < _height; ++i)
		for (int j = 0; j < _width; ++j)
			_colors[i][j] = 0;
}

void Screen::replace(int x, int y, int color) {
	if (x >= _x + _width || y >= _y + _height) return;
	if (x < 0 || y < 0) return;
	_colors[y][x] = color;
}