#include "../headers/main.h"

/**
 * sdl_hand_wind - handling window process
 * @window: sdl window
 * @screen_width: screen width
 * @screen_height: screen height
 * Return: 0 (success), or 1 (error)
 */
int sdl_hand_wind(SDL_Window **window, int screen_width, int screen_height)
{
	*window = SDL_CreateWindow("Maze",
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			screen_width, screen_height,
			SDL_WINDOW_SHOWN);
	if (*window == NULL)
	{
		SDL_Log("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		SDL_Quit();
		return (1);
	}
	return (0);
}
