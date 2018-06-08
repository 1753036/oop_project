#include "Object.h"

Object::Object(Screen* screen, std::string fileName, int x, int y)
	: _texture(screen, fileName)
	, _border(fileName, x, y)
	, _x(x)
	, _y(y) {
}

void Object::setLoc(int x, int y) {
	setX(x);
	setY(y);
}

void Object::draw() {
	_texture.drawAt(_x, _y);
}

bool Object::isImpact(Object& obj) {
	return _border.isImpact(obj._border);
}