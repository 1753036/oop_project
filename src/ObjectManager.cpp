#include "ObjectManager.h"

ObjectManager::~ObjectManager() {
	for (auto obj : _listObj)
		delete obj;
	_listObj.clear();
}

void ObjectManager::drawAll() {
	for (auto obj : _listObj)
		obj->draw();
}

Object* ObjectManager::create(std::string fileName, int x, int y) {
	Object* obj = new Object(_screen, fileName, x, y);
	_listObj.push_front(obj);
	return obj;
}

void ObjectManager::erase(Object* obj) {
	_listObj.remove(obj);
	delete obj;
}

bool ObjectManager::isImpact(Object* otherObj) {
	for (auto obj : _listObj) {
		
		if (obj != otherObj) {
			if (otherObj->isImpact(*obj))
				return true;
		}
	}
	return false;
}