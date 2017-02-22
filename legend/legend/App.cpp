#include "App.h"
#include "SDL\SDL.h"
#include "Window.h"

App::App()
{
}


App::~App()
{
}

void App::run()
{
	bool running = true;
	SDL_Event e;
	
	Window* window = new Window();

	window->init();

	while (running)
	{

		// Handle events in queue
		while (SDL_PollEvent(&e) != 0)
		{
			// Quit if the user requests it. 
			if (e.type == SDL_QUIT)
			{
				running = false;
			}
		}
		
	}

	window->destroy();

	SDL_Quit();
}