#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <conio.h>
#include <Windows.h>

#define COLOR_FOREGROUND 7
#define KB_L 108
#define KB_LEFT 77
#define KB_RIGHT 75
#define KB_UP 72
#define KB_DOWN 80
#define KB_ESC 27

// default console size 128x32
void fixWindowConsole();

// get current console buffer size
void getConsoleBufferSize(int &w, int &h);

void showConsoleCursor(bool showFlag);

// set background color
void setBgColor(WORD color);

//set foreground color
void setFgColor(WORD color);

// origin(0, 0)
void moveCursor(int x, int y);
