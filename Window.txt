#include "Window.h"
#include<iostream>
Window::Window(string title, int width, int height) :
	_title(title), _width(width), _height(height)
{
	if (!init()) {
		_closed = true;
	}
	_closed = !init();
}

Window::~Window() {
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	SDL_QUIT;
}

bool Window::init() {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		cerr << "Failed to initialize SDL" << endl;
		return false;
	}

	_window = SDL_CreateWindow(
		_title.c_str(),
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		_width, _height,
		0
	);

	if (_window == nullptr) {
		cerr << "Failed to create Window" << endl;
		return false;
	}

	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
	if (_renderer == nullptr) {
		cerr << "Failed to create renderer" << endl;
		return false;
	}

	return true;
}

void Window::pollEvents() {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			_closed = true;
			break;
		default:
			break;
		}

	}
}

void Window::clear() const {
	SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
	SDL_RenderClear(_renderer);
}