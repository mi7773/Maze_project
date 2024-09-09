#include "../headers/main.h"

/**
 * sdl_hand - handling sdl processes
 * @window: sdl window
 * @renderer: sdl renderer
 * @screen_width: screen width
 * @screen_height: screen height
 * Return: 0 (success), or 1 (error)
 */
SDL_Texture **sdl_hand(SDL_Window **window, SDL_Renderer **renderer,
		int screen_width, int screen_height)
{
	SDL_Texture **text = NULL;
	SDL_Surface *loaded_surface = NULL;
	char *path[] = {"textures/maze.png", "textures/ceil.jpg", "textures/wall.jpg",
		"textures/ground.jpg", "textures/enemy.png", "textures/w0.png",
		"textures/w1.png", "textures/w2.png", "textures/w3.png", "textures/w4.png",
		"textures/w5.png"};
	int i = 0;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		SDL_Log("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return (NULL);
	}
	if (sdl_hand_wind(window, screen_width, screen_height) == 1)
		return (NULL);
	if (sdl_hand_rend(window, renderer) == 1)
		return (NULL);
	text = sdl_hand_malloc();
	if (text == NULL)
		return (NULL);
	while (i < 11)
	{
		if (sdl_hand_surf(window, renderer, &loaded_surface, path[i]) == 1)
			return (NULL);
		if (sdl_hand_text(window, renderer, &loaded_surface, &text[i]) == 1)
			return (NULL);
		i++;
	}
	text[i] = NULL;
	return (text);
}
