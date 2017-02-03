#pragma once

#include "SDL\SDL.h"

class Window
{
public:
	Window();
	~Window();

	void init();
	void destroy();

private:
	SDL_Window* win;
	SDL_Surface* surface;
	int windowHeight;
	int windowWidth;

};

