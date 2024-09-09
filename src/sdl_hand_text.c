#include "../headers/main.h"

/**
 * sdl_hand_text - handling texture process
 * @window: sdl window
 * @renderer: sdl renderer
 * @loaded_surface: sdl surface
 * @texture: sdl texture
 * Return: 0 (success), or 1 (error)
 */
int sdl_hand_text(SDL_Window **window, SDL_Renderer **renderer,
		SDL_Surface **loaded_surface, SDL_Texture **texture)
{
	*texture = SDL_CreateTextureFromSurface(*renderer, *loaded_surface);
	SDL_FreeSurface(*loaded_surface);
	*loaded_surface = NULL;
	if (*texture == NULL)
	{
		SDL_Log("Unable to create texture! SDL_Error: %s\n", SDL_GetError());
		SDL_DestroyRenderer(*renderer);
		*renderer = NULL;
		SDL_DestroyWindow(*window);
		*window = NULL;
		SDL_Quit();
		return (1);
	}
	return (0);
}
