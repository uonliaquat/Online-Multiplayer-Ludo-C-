#include"Board.h"
#include<iostream>
Board::Board(const Window & window, int w, int h, int a) :
	Window(window), _w(w), _h(h), _a(a)
{

}

void Board::draw() {
	Board::Blocks();
}



void Board::pollEvent() {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		if (event.type == SDL_KEYDOWN) {
			switch (event.key.keysym.sym) {
			case SDLK_LEFT:
				cout << "left" << endl;
				_x -= 50;
				break;
			case SDLK_RIGHT:
				cout << "Right" << endl;
				_x += 50;
				break;
			case SDLK_UP:
				cout << "UP" << endl;
				_y -= 50;
				break;
			case SDLK_DOWN:
				cout << "Down" << endl;
				_y += 50;
				break;
			}
		}
	}
}
void Board::Blocks() {
	SDL_Rect rect;
	for (int i = 0; i < 4; i++) {
		rect.w = _w;
		rect.h = _h;

		if (i == 0) {
			rect.x = 930 - _w;
			rect.y = 0;
			_r = 255;
			_g = 0;
			_b = 0;
		}
		else if (i == 1) {
			rect.x = 0;
			rect.y = 0;
			_r = 0;
			_g = 255;
			_b = 0;
		}
		else if (i == 2) {
			rect.x = 0;
			rect.y = 930 - _h;
			_r = 0;
			_g = 0;
			_b = 255;
		}
		else if (i == 3) {
			rect.x = 930 - _w;
			rect.y = 930 - _h;
			_r = 255;
			_g = 255;
			_b = 0;
		}


		SDL_SetRenderDrawColor(_renderer, _r, _g, _b, _a);
		SDL_RenderFillRect(_renderer, &rect);
	}
	Board::Lines();
	Board::Home();
	Board::Starts();
	Board::Stops();
	Board::WhiteBlocks();
	SDL_RenderPresent(_renderer);
}
void Board::Lines() {
	SDL_SetRenderDrawColor(_renderer, 0, 0, 0, _a);

	//Player 1 lines
	for (int i = 58; i <= 350; i = i + 58) {
		SDL_RenderDrawLine(_renderer, 350, i, 580, i);
	}

	//Player 2 lines
	for (int i = 58; i <= 350; i = i + 58) {
		SDL_RenderDrawLine(_renderer, i, 350, i, 580);
	}

	//Player 3 lines
	for (int i = 580; i <= 872; i = i + 58) {
		SDL_RenderDrawLine(_renderer, 350, i, 580, i);
	}


	//Player 4 lines
	for (int i = 580; i <= 872; i = i + 58) {
		SDL_RenderDrawLine(_renderer, i, 350, i, 580);
	}
}
void Board::Home() {
	SDL_Rect rect;

	//Player 1 Home
	rect.x = 424;
	rect.y = 0;
	_r = 255;
	_g = 0;
	_b = 0;
	rect.w = 80;
	rect.h = 350;
	SDL_SetRenderDrawColor(_renderer, _r, _g, _b, _a);
	SDL_RenderFillRect(_renderer, &rect);



	//Player 2 Home
	rect.x = 0;
	rect.y = 424;
	_r = 0;
	_g = 255;
	_b = 0;
	rect.w = 350;
	rect.h = 80;
	SDL_SetRenderDrawColor(_renderer, _r, _g, _b, _a);
	SDL_RenderFillRect(_renderer, &rect);

	//Player 3 Home
	rect.x = 424;
	rect.y = 580;
	_r = 0;
	_g = 0;
	_b = 255;
	rect.w = 80;
	rect.h = 350;
	SDL_SetRenderDrawColor(_renderer, _r, _g, _b, _a);
	SDL_RenderFillRect(_renderer, &rect);

	//Player 4 Home
	rect.x = 580;
	rect.y = 424;
	_r = 255;
	_g = 255;
	_b = 0;
	rect.w = 350;
	rect.h = 80;
	SDL_SetRenderDrawColor(_renderer, _r, _g, _b, _a);
	SDL_RenderFillRect(_renderer, &rect);

}
void Board::Starts() {
	SDL_Rect rect;

	//Player 1 Start
	rect.x = 500;
	rect.y = 57;
	_r = 255;
	_g = 0;
	_b = 0;
	rect.w = 90;
	rect.h = 60;
	SDL_SetRenderDrawColor(_renderer, _r, _g, _b, _a);
	SDL_RenderFillRect(_renderer, &rect);

	//Player 2 Start
	rect.x = 58;
	rect.y = 350;
	_r = 0;
	_g = 255;
	_b = 0;
	rect.w = 60;
	rect.h = 90;
	SDL_SetRenderDrawColor(_renderer, _r, _g, _b, _a);
	SDL_RenderFillRect(_renderer, &rect);

	//Player 3 Start
	rect.x = 350;
	rect.y = 813;
	_r = 0;
	_g = 0;
	_b = 255;
	rect.w = 90;
	rect.h = 60;
	SDL_SetRenderDrawColor(_renderer, _r, _g, _b, _a);
	SDL_RenderFillRect(_renderer, &rect);

	//Player 4 Home
	rect.x = 811;
	rect.y = 500;
	_r = 255;
	_g = 255;
	_b = 0;
	rect.w = 60;
	rect.h = 90;
	SDL_SetRenderDrawColor(_renderer, _r, _g, _b, _a);
	SDL_RenderFillRect(_renderer, &rect);
}
void Board::Stops() {
	SDL_Rect rect;

	_r = 200;
	_g = 100;
	_b = 0 ;

	//Player 1 Stop
	rect.x = 370;
	rect.y = 135;
	rect.w = 30;
	rect.h = 20;
	SDL_SetRenderDrawColor(_renderer, _r, _g, _b, _a);
	SDL_RenderFillRect(_renderer, &rect);

	//Player 2 Stop
	rect.x = 80;
	rect.y = 530;
	rect.w = 20;
	rect.h = 30;
	SDL_SetRenderDrawColor(_renderer, _r, _g, _b, _a);
	SDL_RenderFillRect(_renderer, &rect);

	//Player 3 Stop
	rect.x = 528;
	rect.y = 775;
	rect.w = 30;
	rect.h = 20;
	SDL_SetRenderDrawColor(_renderer, _r, _g, _b, _a);
	SDL_RenderFillRect(_renderer, &rect);

	//Player 4 Stop
	rect.x = 775;
	rect.y = 375;
	rect.w = 20;
	rect.h = 30;
	SDL_SetRenderDrawColor(_renderer, _r, _g, _b, _a);
	SDL_RenderFillRect(_renderer, &rect);
}
void Board::WhiteBlocks() {
	SDL_Rect rect;
	for (int i = 0; i < 4; i++) {
		rect.w = 200;
		rect.h = 200;
		_r = 211;
		_g = 211;
		_b = 211;
		if (i == 0) {
			rect.x = 655;
			rect.y = 70;

		}
		else if (i == 1) {
			rect.x = 70;
			rect.y = 70;
		}
		else if (i == 2) {
			rect.x = 70;
			rect.y = 660;
		}
		else if (i == 3) {
			rect.x = 655;
			rect.y = 660;
		}
		SDL_SetRenderDrawColor(_renderer, _r, _g, _b, _a);
		SDL_RenderFillRect(_renderer, &rect);
	}
}