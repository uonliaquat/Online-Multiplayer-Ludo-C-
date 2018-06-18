#pragma once
#include"Window.h"
#include "Coin.h"
#include<string>

class Board : public Window {

public:
	Board(const Window & window, int w, int h, int a);

	void draw();
	void pollEvent();
	void Blocks();
	void Lines();
	void Home();
	void Starts();
	void Stops();
	void WhiteBlocks();
private:
	int _w, _h;
	int _x, _y;
	int _r, _g, _b, _a;
};
