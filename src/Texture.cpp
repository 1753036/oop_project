#include "Texture.h"

Texture::Texture(Screen* screen, std::string fileName) 
	: _screen(screen)
{
	loadFromFile(fileName);
}

Texture::Texture(const Texture& txr) 
	: _screen(txr._screen)
{
	alloc(txr._dataX, txr._dataY, txr._colors, txr._size);
}

Texture::~Texture() {
	destroy();
}

Texture& Texture::operator=(const Texture& txr) {
	_screen = txr._screen;
	destroy();
	alloc(txr._dataX, txr._dataY, txr._colors, txr._size);
	return *this;
}

void Texture::destroy() {
	//std::cout << "destroy " << this << std::endl;

	delete[] _dataX;
	delete[] _dataY;
	delete[] _colors;
}

void Texture::alloc(int* x, int* y, int* colors, int size) {
	destroy();
	alloc(size);
	for (int i = 0; i < _size; ++i) {
		_dataX[i] = x[i];
		_dataY[i] = y[i];
		_colors[i] = colors[i];
	}
}

void Texture::alloc(int size) {
	//std::cout << "allocate " << this << std::endl;

	_size = size;
	_dataX = new int[_size];
	_dataY = new int[_size];
	_colors = new int[_size];
}

void Texture::loadFromFile(std::string fileName) {
	std::ifstream in(fileName.c_str());

	if (in.is_open() == false) {
		std::cout << "File not found: " << fileName << std::endl;
		return;
	}

	std::string buff;

	while (std::getline(in, buff)) {
		if (buff[0] == '#') continue;
		if (buff == "[Texture]") {
			in >> _size;

			destroy();
			alloc(_size);
			for (int i = 0; i < _size; ++i)
				in >> _dataX[i] >> _dataY[i] >> _colors[i];
		}
	}

	in.close();
}

void Texture::clear() {
	for (int i = 0; i < _size; ++i) {

	}
}

void Texture::drawAt(int x, int y) {
	for (int i = 0; i < _size; ++i)
		_screen->replace(_dataX[i] + x, _dataY[i] + y, _colors[i]);
}


void Texture::rotate() {
	int midX = _dataX[0];
	int midY = _dataY[0];

	for (int i = 0; i < _size; ++i) {
		int x = _dataY[i] - midY;
		int y = _dataX[i] - midX;
		_dataX[i] = midX - x;
		_dataY[i] = midY + y;
	}
}

