#include "../headers/main.h"

/**
 * sdl_hand_surf - handling surface process
 * @window: sdl window
 * @renderer: sdl renderer
 * @loaded_surface: sdl surface
 * @path: image path
 * Return: 0 (success), or 1 (error)
 */
int sdl_hand_surf(SDL_Window **window, SDL_Renderer **renderer,
		SDL_Surface **loaded_surface, char *path)
{
	*loaded_surface = IMG_Load(path);
	if (*loaded_surface == NULL)
	{
		SDL_Log("Unable to load image! SDL_Image_Error: %s\n", IMG_GetError());
		SDL_DestroyRenderer(*renderer);
		*renderer = NULL;
		SDL_DestroyWindow(*window);
		*window = NULL;
		SDL_Quit();
		return (1);
	}
	return (0);
}
