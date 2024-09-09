#include "../headers/main.h"

/**
 * sdl_hand_rend - handling renderer process
 * @window: sdl window
 * @renderer: sdl renderer
 * Return: 0 (success), or 1 (error)
 */
int sdl_hand_rend(SDL_Window **window, SDL_Renderer **renderer)
{
	*renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
	if (*renderer == NULL)
	{
		SDL_Log("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
		SDL_DestroyWindow(*window);
		*window = NULL;
		SDL_Quit();
		return (1);
	}
	return (0);
}
