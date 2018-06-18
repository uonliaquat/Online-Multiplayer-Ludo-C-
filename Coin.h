#pragma once

#include"Window.h"
#include<time.h>
#include <cstdlib>
#include <ctime>
class Coin :public Window {
public:
	Coin(const Window & window, int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4,
		int xt1, int yt1, int xt2, int yt2, int xt3, int yt3, int xt4, int yt4, int a);

	void draw();
	void PlayerOneCoins();
	void PlayerTwoCoins();
	void pollEvent();
	int Get_X1();
	int Get_X2();
	int Get_X3();
	int Get_X4();
	int Get_Y1();
	int Get_Y2();
	int Get_Y3();
	int Get_Y4();

	void Set_x1(int newx);
	void Set_x2(int newx);
	void Set_x3(int newx);
	void Set_x4(int newx);
	void Set_y1(int newy);
	void Set_y2(int newy);
	void Set_y3(int newy);
	void Set_y4(int newy);
	void Kill();
	void SetCheckTurn(char c);
	char GetCheckTurn();

	bool Stops_xt();
	bool Stops_xt2();
	bool Stops_xt3();
	bool Stops_xt4();

	void CoinCheck();
	bool GameWIn();

private:
	int _w, _h;
	int _x, _y;
	int _x2, _y2;
	int _x3, _y3;
	int _x4, _y4;
	int _xt, _yt;
	int _xt2, _yt2;
	int _xt3, _yt3;
	int _xt4, _yt4;
	int _r, _g, _b, _a;
	int diceRoll = 0;
	bool six = false;
	int Player1_turn = 0;
	bool coinIn[4] = { false,false,false,false};
	int total_dice_frequency = 0;
	int startCheck[4] = { 0,0,0,0 };
	int CoinCleared[4] = { false,false,false,false};
	bool homeCheck = false;

	char checkTurn = 'n';

};
