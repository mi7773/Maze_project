#include "../headers/main.h"

/**
 * sdl_hand_malloc - handling malloc process
 * Return: array of pointers to sdl texture
 */
SDL_Texture **sdl_hand_malloc(void)
{
	SDL_Texture **text = (SDL_Texture **) malloc(12 * sizeof(SDL_Texture *));

	if (text == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		return (NULL);
	}
	return (text);
}
