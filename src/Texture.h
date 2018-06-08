#pragma once

#include "Screen.h"

class Texture {
private:
	Screen* _screen;
	int*	_dataX;
	int*	_dataY;
	int*	_colors;
	int		_size;

	void destroy();
	void alloc(int size);
	void alloc(int* x, int* y, int* colors, int size);
public:
	Texture(Screen* screen, std::string fileName);
	Texture(const Texture&);
	~Texture();

	Texture& operator=(const Texture&);

	void loadFromFile(std::string fileName);
	
	void clear();

	//buggggggggggggg BUGGGGGGGGGGGGGGGGGGGG BBBBUUUUGGGG
	void rotate();

	void drawAt(int x, int y);
};