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
		return;
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

		
		SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0x00, 0x00, 0xFF));

		//Update the surface
		SDL_UpdateWindowSurface(win);

		//Wait two seconds
		SDL_Delay(2000);
	}
}

void Window::destroy()
{
	SDL_DestroyWindow(win); // Screen surface (surface) will be destroyed along with the window.
	win = nullptr;
	//SDL_Quit(); // Temp location(?)
}
