#include "../headers/main.h"

/**
 * sdl_close - closing sdl
 * @window: sdl window
 * @renderer: sdl renderer
 * @text: array of pointers to sdl texture
 */
void sdl_close(SDL_Window **window, SDL_Renderer **renderer,
		SDL_Texture **text)
{
	int i = 11;

	while (i >= 0)
	{
		SDL_DestroyTexture(text[i]);
		i--;
	}
	free(text);
	SDL_DestroyRenderer(*renderer);
	*renderer = NULL;
	SDL_DestroyWindow(*window);
	*window = NULL;
	SDL_Quit();
}
