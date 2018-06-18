#include"Coin.h"
#include<iostream>
#include <cstdlib>
#include <ctime>
Coin::Coin(const Window & window, int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4,
			int xt1, int yt1, int xt2, int yt2, int xt3, int yt3, int xt4, int yt4, int a) :
	Window(window), _x(x1), _y(y1), _x2(x2), _y2(y2), _x3(x3), _y3(y3), _x4(x4), _y4(y4),
	_xt(xt1), _yt(yt1), _xt2(xt2), _yt2(yt2), _xt3(xt3), _yt3(yt3), _xt4(xt4), _yt4(yt4), _a(a)
{
	srand((unsigned)time(0));

}
SDL_Rect rect[4];
SDL_Rect rect2[4];
void Coin::draw() {
	PlayerOneCoins();
	PlayerTwoCoins();
	Coin::pollEvent();
}

void Coin::PlayerOneCoins() {
	//Coin 1
	rect[0].x = _x;
	rect[0].y = _y;
	rect[0].w = 40;
	rect[0].h = 40;
	_r = 0;
	_g = 0;
	_b = 150;
	

	//Coin 2
	rect[1].x = _x2;
	rect[1].y = _y2;
	rect[1].w = 40;
	rect[1].h = 40;

	//Coin 3
	rect[2].x = _x3;
	rect[2].y = _y3;
	rect[2].w = 40;
	rect[2].h = 40;

	//Coin 4
	rect[3].x = _x4;
	rect[3].y = _y4;
	rect[3].w = 40;
	rect[3].h = 40;
	SDL_SetRenderDrawColor(_renderer, _r, _g, _b, 255);
	SDL_RenderFillRect(_renderer, &rect[0]);
	SDL_RenderFillRect(_renderer, &rect[1]);
	SDL_RenderFillRect(_renderer, &rect[2]);
	SDL_RenderFillRect(_renderer, &rect[3]);
}
void Coin::PlayerTwoCoins() {
	//Coin 1
	rect2[0].x = _xt;
	rect2[0].y = _yt;
	rect2[0].w = 40;
	rect2[0].h = 40;
	_r = 150;
	_g = 0;
	_b = 0;


	//Coin 2
	rect2[1].x = _xt2;
	rect2[1].y = _yt2;
	rect2[1].w = 40;
	rect2[1].h = 40;

	//Coin 3
	rect2[2].x = _xt3;
	rect2[2].y = _yt3;
	rect2[2].w = 40;
	rect2[2].h = 40;

	//Coin 4
	rect2[3].x = _xt4;
	rect2[3].y = _yt4;
	rect2[3].w = 40;
	rect2[3].h = 40;
	SDL_SetRenderDrawColor(_renderer, _r, _g, _b, 255);
	SDL_RenderFillRect(_renderer, &rect2[0]);
	SDL_RenderFillRect(_renderer, &rect2[1]);
	SDL_RenderFillRect(_renderer, &rect2[2]);
	SDL_RenderFillRect(_renderer, &rect2[3]);
	for (int i = 0; i < 30; i++) {
		SDL_RenderPresent(_renderer);
	}
}

void Coin::pollEvent() {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		if (event.type == SDL_KEYDOWN) {
			switch (event.key.keysym.sym) {
			case SDLK_q:
				exit(1);
			case SDLK_SPACE:
				checkTurn = 's';
				diceRoll = (rand() % 6) + 1;
				cout << "Dice: " << diceRoll << endl;
				break;
			case SDLK_1:
				checkTurn = 's';
				if (!coinIn[0] && diceRoll == 6) {
					_x = 370;
					rect[0].x = _x;
					_y = 825;
					rect[0].y = _y;
					coinIn[0] = true;
					//cout << "_x: " << _x << endl;
					//cout << "_y: " << _y << endl;
				}
				startCheck[0]++;
				if (startCheck[0] > 1) {
					for (int i = 0; i < diceRoll; i++) {
						if (coinIn[0]) {
							if (_y > 550 && _x != 520) {
								_y = _y - 60;
								rect[0].y = _y;
								if (_x == 370 && _y == 525) {
									_x = 310;
								}
								//cout << "_x: " << _x << endl;
								//cout << "_y: " << _y << endl;
							}
							else if (_y == 525 && _x > 20 && _x < 500) {
								_x = _x - 60;
								rect[0].x = _x;
								//cout << "_x: " << _x << endl;
								//cout << "_y: " << _y << endl;
							}
							else if (_y <= 550 && _x <= 20 && _y >= 440) {
								_y = _y - 80;
								rect[0].y = _y;
								//cout << "_x: " << _x << endl;
								//cout << "_y: " << _y << endl;
							}
							else if (_x >= 10 && _y == 365 && _x < 311) {
								_x = _x + 60;
								rect[0].x = _x;
								if (_x == 370 && _y == 365) {
									_y = 305;
								}
								//cout << "_x: " << _x << endl;
								//cout << "_y: " << _y << endl;
							}
							else if (_x >= 370 && _y <= 365 && _y > 5 && _x != 520 && _x < 520) {
								_y = _y - 60;
								rect[0].y = _y;
								//cout << "_x: " << _x << endl;
								//cout << "_y: " << _y << endl;
							}
							else if (_x >= 370 && _x <= 445 && _y == 5) {
								_x = _x + 75;
								rect[0].x = _x;
								//cout << "_x: " << _x << endl;
								//cout << "_y: " << _y << endl;
							}
							else if (_x == 520 && _y >= 5 && _y < 365) {
								_y = _y + 60;
								rect[0].y = _y;
								if (_x == 520 && _y == 365) {
									_x = 580;
								}
								//cout << "_x: " << _x << endl;
								//cout << "_y: " << _y << endl;
							}
							else if (_x >= 520 && _y >= 365 && _x < 880 && _y < 525) {
								_x = _x + 60;
								rect[0].x = _x;
								//cout << "_x: " << _x << endl;
								//cout << "_y: " << _y << endl;
							}
							else if (_x >= 880 && _y >= 365 && _y < 525) {
								_y = _y + 80;
								rect[0].y = _y;
								//cout << "_x: " << _x << endl;
								//cout << "_y: " << _y << endl;
							}
							else if (_x <= 880 && _y >= 525 && _x > 520) {
								_x = _x - 60;
								rect[0].x = _x;
								if (_x == 520 && _y == 525) {
									_y = 585;
								}
								//cout << "_x: " << _x << endl;
								//cout << "_y: " << _y << endl;
							}
							else if (_x == 520 && _y >= 525 && _y < 885) {
								_y = _y + 60;
								rect[0].y = _y;
								//cout << "_x: " << _x << endl;
								//cout << "_y: " << _y << endl;
							}
							else if (_x <= 520 && _y == 885) {
								_x = _x - 80;
								rect[0].x = _x;
								//cout << "_x: " << _x << endl;
								//cout << "_y: " << _y << endl;
							}
							else if (_x == 440 && _y <= 885) {
								_y = _y - 80;
								rect[0].y = _y;
								//cout << "_x: " << _x << endl;
								//cout << "_y: " << _y << endl;
							}
						}
					}
				}
				break;
			case SDLK_2:
				checkTurn = 's';
				if (!coinIn[1] && diceRoll == 6) {
					_x2 = 370;
					rect[1].x = _x2;
					_y2 = 825;
					rect[1].y = _y2;
					coinIn[1] = true;
				}
				startCheck[1]++;
				if (startCheck[1] > 1) {
					for (int i = 0; i < diceRoll; i++) {
						if (coinIn[1]) {
							if (_y2 > 550 && _x2 != 520) {
								_y2 = _y2 - 60;
								rect[1].y = _y2;
								if (_x2 == 370 && _y2 == 525) {
									_x2 = 310;
								}
								cout << "1" << endl;
							}
							else if (_y2 == 525 && _x2 > 20 && _x2 < 500) {
								_x2 = _x2 - 60;
								rect[1].x = _x2;
								cout << "2" << endl;
							}
							else if (_y2 <= 550 && _x2 <= 20 && _y2 >= 440) {
								_y2 = _y2 - 80;
								rect[1].y = _y2;
								cout << "3" << endl;
							}
							else if (_x2 >= 10 && _y2 == 365 && _x2 < 311) {
								_x2 = _x2 + 60;
								rect[1].x = _x2;
								if (_x2 == 370 && _y2 == 365) {
									_y2 = 305;
								}
								cout << "4" << endl;
							}
							else if (_x2 >= 370 && _y2 <= 365 && _y2 > 5 && _x2 != 520 && _x2 < 520) {
								_y2 = _y2 - 60;
								rect[1].y = _y2;
								cout << "5" << endl;
							}
							else if (_x2 >= 370 && _x2 <= 445 && _y2 == 5) {
								_x2 = _x2 + 75;
								rect[1].x = _x2;
								cout << "6" << endl;
							}
							else if (_x2 == 520 && _y2 >= 5 && _y2 < 365) {
								_y2 = _y2 + 60;
								rect[1].y = _y2;
								if (_x2 == 520 && _y2 == 365) {
									_x2 = 580;
								}
								cout << "7" << endl;
							}
							else if (_x2 >= 520 && _y2 >= 365 && _x2 < 880 && _y2 < 525) {
								_x2 = _x2 + 60;
								rect[1].x = _x2;
								cout << "8" << endl;
							}
							else if (_x2 >= 880 && _y2 >= 365 && _y2 < 525) {
								_y2 = _y2 + 80;
								rect[1].y = _y2;
								cout << "9" << endl;
							}
							else if (_x2 <= 880 && _y2 >= 525 && _x2 > 520) {
								_x2 = _x2 - 60;
								rect[1].x = _x2;
								if (_x2 == 520 && _y2 == 525) {
									_y2 = 585;
								}
								cout << "10" << endl;
							}
							else if (_x2 == 520 && _y2 >= 525 && _y2 < 885) {
								_y2 = _y2 + 60;
								rect[1].y = _y2;
								cout << "11" << endl;
							}
							else if (_x2 <= 520 && _y2 == 885) {
								_x2 = _x2 - 80;
								rect[1].x = _x2;
								cout << "12" << endl;
							}
							else if (_x2 == 440 && _y2 <= 885) {
								_y2 = _y2 - 80;
								rect[1].y = _y2;
								cout << "13" << endl;
							}
						}
					}
					cout << _x << endl;
					cout << _y << endl;
				}
					break;
			case SDLK_3:
				checkTurn = 's';
				if (!coinIn[2] && diceRoll == 6) {
					_x3 = 370;
					rect[2].x = _x3;
					_y3 = 825;
					rect[2].y = _y3;
					coinIn[2] = true;
				}
				startCheck[2]++;
				if (startCheck[2] > 1) {
					for (int i = 0; i < diceRoll; i++) {
						if (coinIn[2]) {
							if (_y3 > 550 && _x3 != 520) {
								_y3 = _y3 - 60;
								rect[2].y = _y3;
								if (_x3 == 370 && _y3 == 525) {
									_x3 = 310;
								}
								cout << "1" << endl;
							}
							else if (_y3 == 525 && _x3 > 20 && _x3 < 500) {
								_x3 = _x3 - 60;
								rect[2].x = _x3;
								cout << "2" << endl;
							}
							else if (_y3 <= 550 && _x3 <= 20 && _y3 >= 440) {
								_y3 = _y3 - 80;
								rect[2].y = _y3;
								cout << "3" << endl;
							}
							else if (_x3 >= 10 && _y3 == 365 && _x3 < 311) {
								_x3 = _x3 + 60;
								rect[2].x = _x3;
								if (_x3 == 370 && _y3 == 365) {
									_y3 = 305;
								}
								cout << "4" << endl;
							}
							else if (_x3 >= 370 && _y3 <= 365 && _y3 > 5 && _x3 != 520 && _x3 < 520) {
								_y3 = _y3 - 60;
								rect[2].y = _y3;
								cout << "5" << endl;
							}
							else if (_x3 >= 370 && _x3 <= 445 && _y3 == 5) {
								_x3 = _x3 + 75;
								rect[2].x = _x3;
								cout << "6" << endl;
							}
							else if (_x3 == 520 && _y3 >= 5 && _y3 < 365) {
								_y3 = _y3 + 60;
								rect[2].y = _y3;
								if (_x3 == 520 && _y3 == 365) {
									_x3 = 580;
								}
								cout << "7" << endl;
							}
							else if (_x3 >= 520 && _y3 >= 365 && _x3 < 880 && _y3 < 525) {
								_x3 = _x3 + 60;
								rect[2].x = _x3;
								cout << "8" << endl;
							}
							else if (_x3 >= 880 && _y3 >= 365 && _y3 < 525) {
								_y3 = _y3 + 80;
								rect[2].y = _y3;
								cout << "9" << endl;
							}
							else if (_x3 <= 880 && _y3 >= 525 && _x3 > 520) {
								_x3 = _x3 - 60;
								rect[2].x = _x3;
								if (_x3 == 520 && _y3 == 525) {
									_y3 = 585;
								}
								cout << "10" << endl;
							}
							else if (_x3 == 520 && _y3 >= 525 && _y3 < 885) {
								_y3 = _y3 + 60;
								rect[2].y = _y3;
								cout << "11" << endl;
							}
							else if (_x3 <= 520 && _y3 == 885) {
								_x3 = _x3 - 80;
								rect[2].x = _x3;
								cout << "12" << endl;
							}
							else if (_x3 == 440 && _y3 <= 885) {
								_y3 = _y3 - 80;
								rect[2].y = _y3;
								cout << "13" << endl;
							}
						}
					}
					cout << _x << endl;
					cout << _y << endl;
				}
					break;
			case SDLK_4:
				checkTurn = 's';
				if (!coinIn[3] && diceRoll == 6) {
					_x4 = 370;
					rect[2].x = _x4;
					_y4 = 825;
					rect[2].y = _y4;
					coinIn[3] = true;
				}
				startCheck[3]++;
				if (startCheck[3] > 1) {
					for (int i = 0; i < diceRoll; i++) {
						if (coinIn[3]) {
							if (_y4 > 550 && _x4 != 520) {
								_y4 = _y4 - 60;
								rect[3].y = _y4;
								if (_x4 == 370 && _y4 == 525) {
									_x4 = 310;
								}
								cout << "1" << endl;
							}
							else if (_y4 == 525 && _x4 > 20 && _x4 < 500) {
								_x4 = _x4 - 60;
								rect[3].x = _x4;
								cout << "2" << endl;
							}
							else if (_y4 <= 550 && _x4 <= 20 && _y4 >= 440) {
								_y4 = _y4 - 80;
								rect[3].y = _y4;
								cout << "3" << endl;
							}
							else if (_x4 >= 10 && _y4 == 365 && _x4 < 311) {
								_x4 = _x4 + 60;
								rect[3].x = _x4;
								if (_x4 == 370 && _y4 == 365) {
									_y4 = 305;
								}
								cout << "4" << endl;
							}
							else if (_x4 >= 370 && _y4 <= 365 && _y4 > 5 && _x4 != 520 && _x4 < 520) {
								_y4 = _y4 - 60;
								rect[3].y = _y4;
								cout << "5" << endl;
							}
							else if (_x4 >= 370 && _x4 <= 445 && _y4 == 5) {
								_x4 = _x4 + 75;
								rect[3].x = _x4;
								cout << "6" << endl;
							}
							else if (_x4 == 520 && _y4 >= 5 && _y4 < 365) {
								_y4 = _y4 + 60;
								rect[3].y = _y4;
								if (_x4 == 520 && _y4 == 365) {
									_x4 = 580;
								}
								cout << "7" << endl;
							}
							else if (_x4 >= 520 && _y4 >= 365 && _x4 < 880 && _y4 < 525) {
								_x4 = _x4 + 60;
								rect[3].x = _x4;
								cout << "8" << endl;
							}
							else if (_x4 >= 880 && _y4 >= 365 && _y4 < 525) {
								_y4 = _y4 + 80;
								rect[3].y = _y4;
								cout << "9" << endl;
							}
							else if (_x4 <= 880 && _y4 >= 525 && _x4 > 520) {
								_x4 = _x4 - 60;
								rect[3].x = _x4;
								if (_x4 == 520 && _y4 == 525) {
									_y4 = 585;
								}
								cout << "10" << endl;
							}
							else if (_x4 == 520 && _y4 >= 525 && _y4 < 885) {
								_y4 = _y4 + 60;
								rect[3].y = _y4;
								cout << "11" << endl;
							}
							else if (_x4 <= 520 && _y4 == 885) {
								_x4 = _x4 - 80;
								rect[3].x = _x4;
								cout << "12" << endl;
							}
							else if (_x4 == 440 && _y4 <= 885) {
								_y4 = _y4 - 80;
								rect[3].y = _y4;
								cout << "13" << endl;
							}
						}
					}
					cout << _x << endl;
					cout << _y << endl;
				}
					break;
			}
			//SDL_RenderPresent(_renderer);

		}

	}

}
int Coin::Get_X1(){ return _x; }
int Coin::Get_X2(){ return _x2; }
int Coin::Get_X3(){ return _x3; }
int Coin::Get_X4(){ return _x4; }
int Coin::Get_Y1(){ return _y; }
int Coin::Get_Y2(){ return _y2; }
int Coin::Get_Y3(){ return _y3; }
int Coin::Get_Y4(){ return _y4; }

void Coin::Set_x1(int newx){ _xt = newx; }
void Coin::Set_x2(int newx){ _xt2 = newx; }
void Coin::Set_x3(int newx){ _xt3 = newx; }
void Coin::Set_x4(int newx){ _xt4 = newx; }
void Coin::Set_y1(int newy){ _yt = newy; }
void Coin::Set_y2(int newy){ _yt2 = newy; }
void Coin::Set_y3(int newy){ _yt3 = newy; }
void Coin::Set_y4(int newy){ _yt4 = newy; }

bool Coin::Stops_xt() {
	if (_x == 370 && _y == 825) {
		return true;
	}
	else if (_x == 70 && _y == 525) {
		return true;
	}
	else if (_x == 70 && _y == 365) {
		return true;
	}
	else if (_x == 370 && _y == 125) {
		return true;
	}
	else if (_x == 520 && _y == 65) {
		return true;
	}
	else if (_x == 760 && _y == 365) {
		return true;
	}
	else if (_x == 820 && _y == 525) {
		return true;
	}
	else if (_x == 520 && _y == 765) {
		return true;
	}
	else {
		return false;
	}
}
bool Coin::Stops_xt2() {
	if (_x2 == 370 && _y2 == 825) {
		return true;
	}
	else if (_x2 == 70 && _y2 == 525) {
		return true;
	}
	else if (_x2 == 70 && _y2 == 365) {
		return true;
	}
	else if (_x2 == 370 && _y2 == 125) {
		return true;
	}
	else if (_x2 == 520 && _y2 == 65) {
		return true;
	}
	else if (_x2 == 760 && _y2 == 365) {
		return true;
	}
	else if (_x2 == 820 && _y2 == 525) {
		return true;
	}
	else if (_x2 == 520 && _y2 == 765) {
		return true;
	}
	else {
		return false;
	}
}
bool Coin::Stops_xt3() {
	if (_x3 == 370 && _y3 == 825) {
		return true;
	}
	else if (_x3 == 70 && _y3 == 525) {
		return true;
	}
	else if (_x3 == 70 && _y3 == 365) {
		return true;
	}
	else if (_x3 == 370 && _y3 == 125) {
		return true;
	}
	else if (_x3 == 520 && _y3 == 65) {
		return true;
	}
	else if (_x3 == 760 && _y3 == 365) {
		return true;
	}
	else if (_x3 == 820 && _y3 == 525) {
		return true;
	}
	else if (_x3 == 520 && _y3 == 765) {
		return true;
	}
	else {
		return false;
	}
}
bool Coin::Stops_xt4() {
	if (_x4 == 370 && _y4 == 825) {
		return true;
	}
	else if (_x4 == 70 && _y4 == 525) {
		return true;
	}
	else if (_x4 == 70 && _y4 == 365) {
		return true;
	}
	else if (_x4 == 370 && _y4 == 125) {
		return true;
	}
	else if (_x4 == 520 && _y4 == 65) {
		return true;
	}
	else if (_x4 == 760 && _y4 == 365) {
		return true;
	}
	else if (_x4 == 820 && _y4 == 525) {
		return true;
	}
	else if (_x4 == 520 && _y4 == 765) {
		return true;
	}
	else {
		return false;
	}
}

void Coin::Kill() {
	if (checkTurn == 'c') {
		if (!Stops_xt()) {
			if (_xt < _x + 12 && _xt > _x - 12) {
				if (_yt < _y + 12 && _yt > _y - 12) {
					_x = 100;
					_y = 700;
					coinIn[0] = false;
					startCheck[0] = 0;
				}
			}
		}
		if (!Stops_xt2()) {
			if (_xt < _x2 + 12 && _xt > _x2 - 12) {
				if (_yt < _y2 + 12 && _yt > _y2 - 12) {
					_x2 = 200;
					_y2 = 700;
					coinIn[1] = false;
					startCheck[1] = 0;
				}
			}
		}
		if (!Stops_xt3()) {
			if (_xt < _x3 + 12 && _xt > _x3 - 12) {
				if (_yt < _y3 + 12 && _yt > _y3 - 12) {
					_x3 = 100;
					_y3 = 780;
					coinIn[2] = false;
					startCheck[2] = 0;
				}
			}
		}
		if (!Stops_xt4()) {
			if (_xt < _x4 + 12 && _xt > _x4 - 12) {
				if (_yt < _y4 + 12 && _yt > _y4 - 12) {
					_x4 = 200;
					_y4 = 780;
					coinIn[3] = false;
					startCheck[3] = 0;
				}
			}
		}
		if (!Stops_xt()) {
			if (_xt2 < _x + 12 && _xt2 > _x - 12) {
				if (_yt2 < _y + 12 && _yt2 > _y - 12) {
					_x = 100;
					_y = 700;
					coinIn[0] = false;
					startCheck[0] = 0;
				}
			}
		}
		if (!Stops_xt2()) {
			if (_xt2 < _x2 + 12 && _xt2 > _x2 - 12) {
				if (_yt2 < _y2 + 12 && _yt2 > _y2 - 12) {
					_x2 = 200;
					_y2 = 700;
					coinIn[1] = false;
					startCheck[1] = 0;
				}
			}
		}
		if (!Stops_xt3()) {
			if (_xt2 < _x3 + 12 && _xt2 > _x3 - 12) {
				if (_yt2 < _y3 + 12 && _yt2 > _y3 - 12) {
					_x3 = 100;
					_y3 = 780;
					coinIn[2] = false;
					startCheck[2] = 0;
				}
			}
		}
		if (!Stops_xt4()) {
			if (_xt2 < _x4 + 12 && _xt2 > _x4 - 12) {
				if (_yt2 < _y4 + 12 && _yt2 > _y4 - 12) {
					_x4 = 200;
					_y4 = 780;
					coinIn[3] = false;
					startCheck[3] = 0;
				}
			}
		}

		if (!Stops_xt()) {
			if (_xt3 < _x + 12 && _xt3 > _x - 12) {
				if (_yt3 < _y + 12 && _yt3 > _y - 12) {
					_x = 100;
					_y = 700;
					coinIn[0] = false;
					startCheck[0] = 0;
				}
			}
		}
		if (!Stops_xt2()) {
			if (_xt3 < _x2 + 12 && _xt3 > _x2 - 12) {
				if (_yt3 < _y2 + 12 && _yt3 > _y2 - 12) {
					_x2 = 200;
					_y2 = 700;
					coinIn[1] = false;
					startCheck[1] = 0;
				}
			}
		}
		if (!Stops_xt3()) {
			if (_xt3 < _x3 + 12 && _xt3 > _x3 - 12) {
				if (_yt3 < _y3 + 12 && _yt3 > _y3 - 12) {
					_x3 = 100;
					_y3 = 780;
					coinIn[2] = false;
					startCheck[2] = 0;
				}
			}
		}
		if (!Stops_xt4()) {
			if (_xt3 < _x4 + 12 && _xt3 > _x4 - 12) {
				if (_yt3 < _y4 + 12 && _yt3 > _y4 - 12) {
					_x4 = 200;
					_y4 = 780;
					coinIn[3] = false;
					startCheck[3] = 0;
				}
			}
		}
		if (!Stops_xt()) {
			if (_xt4 < _x + 12 && _xt4 > _x - 12) {
				if (_yt4 < _y + 12 && _yt4 > _y - 12) {
					_x = 100;
					_y = 700;
					coinIn[0] = false;
					startCheck[0] = 0;
				}
			}
		}
		if (!Stops_xt2()) {
			if (_xt4 < _x2 + 12 && _xt4 > _x2 - 12) {
				if (_yt4 < _y2 + 12 && _yt4 > _y2 - 12) {
					_x2 = 200;
					_y2 = 700;
					coinIn[1] = false;
					startCheck[1] = 0;
				}
			}
		}
		if (!Stops_xt3()) {
			if (_xt4 < _x3 + 12 && _xt4 > _x3 - 12) {
				if (_yt4 < _y3 + 12 && _yt4 > _y3 - 12) {
					_x3 = 100;
					_y3 = 780;
					coinIn[2] = false;
					startCheck[2] = 0;
				}
			}
		}
		if (!Stops_xt4()) {
			if (_xt4 < _x4 + 12 && _xt4 > _x4 - 12) {
				if (_yt4 < _y4 + 12 && _yt4 > _y4 - 12) {
					_x4 = 200;
					_y4 = 780;
					coinIn[3] = false;
					startCheck[3] = 0;
				}
			}
		}
	}
}
void Coin::SetCheckTurn(char c){
	checkTurn = c;
}
char Coin::GetCheckTurn() {
	return checkTurn;
}

void Coin::CoinCheck() {
	if (_x == 440 && _y == 525) {
		CoinCleared[0] = true;
		_x = 440;
		_y = 478;
	}
	if (_x2 == 440 && _y2 == 525) {
		CoinCleared[1] = true;
		_x2 = 370;
		_y2 = 523;
	}
	if (_x3 == 440 && _y3 == 525) {
		CoinCleared[2] = true;
		_x3 = 440;
		_y3 = 523;
	}
	if (_x4 == 440 && _y4 == 525) {
		CoinCleared[3] = true;
		_x4 = 510;
		_y4 = 523;
	}
}
bool Coin::GameWIn() {
	if (CoinCleared[0] == true && CoinCleared[1] == true && CoinCleared[2] == true && CoinCleared[3] == true) {
		cout << "You Won!" << endl;
		return true;
	}
	else {
		return false;
	}

}