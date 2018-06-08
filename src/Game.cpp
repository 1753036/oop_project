#include "Game.h"

Game::Game()
	: _screen(0, 0, 100, 30)
	, _objman(&_screen)
	, _running(true)
	, _manchar(_objman.create("obj/human.txt", 50, 24))
	, _countEnemies(20)
	, _enemies(new Object*[_countEnemies])
{
	for (int i = 0; i < 10; ++i)
		_enemies[i] = _objman.create("obj/tank.txt", i * 8, 5);

	for (int i = 10; i < _countEnemies; ++i)
		_enemies[i] = _objman.create("obj/bird.txt", (i - 10) * 10 + 5, 15);
}

Game::~Game() {
	delete[] _enemies;
}

void Game::loop() {
	while (_running) {
		move();
		moveE();

		_screen.clear();
		_objman.drawAll();
		_screen.present();
		

		
	}
	moveCursor(0, 0);
}

void Game::gexit() {
	_running = false;
}

void Game::check() {
	if (_objman.isImpact(_manchar))
		_manchar->setLoc(50, 24);
}

void Game::moveE() {
	for (int i = 0; i < 10; ++i) {
		_enemies[i]->setX(_enemies[i]->getX() - 2);
		if (_enemies[i]->getX() <= -4)
			_enemies[i]->setX(100);
	}

	for (int i = 10; i < _countEnemies; ++i) {
		_enemies[i]->setX(_enemies[i]->getX() + 1);
		if (_enemies[i]->getX() >= 100)
			_enemies[i]->setX(-2);
	}
}

void Game::move() {
	//std::cout << GetAsyncKeyState(VK_UP) << std::endl;
	check();

	if (GetAsyncKeyState(VK_UP))
		_manchar->setY(_manchar->getY() - 1);
	if (GetAsyncKeyState(VK_DOWN))
		_manchar->setY(_manchar->getY() + 1);
	if (GetAsyncKeyState(VK_RIGHT))
		_manchar->setX(_manchar->getX() + 1);
	if (GetAsyncKeyState(VK_LEFT))
		_manchar->setX(_manchar->getX() - 1);
}