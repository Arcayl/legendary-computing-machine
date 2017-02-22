#include "Window.h"
#include <stdio.h>

Window::Window() : windowHeight(600), windowWidth(800), win(nullptr), surface(nullptr)
{
}

Window::~Window()
{
}

void Window::init()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL init failure! SDL_Error: %s\n", SDL_GetError());
	}

	win = SDL_CreateWindow("Legendary testbed of legend", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, windowWidth, windowHeight, SDL_WINDOW_SHOWN);

	if (win == nullptr)
	{
		printf("Could not create window! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		surface = SDL_GetWindowSurface(win);
	}
}

void Window::destroy()
{
	SDL_DestroyWindow(win);
}
