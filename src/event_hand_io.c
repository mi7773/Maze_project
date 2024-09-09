#include "../headers/main.h"

/**
 * event_hand_io - handling io graphics
 * @renderer: sdl renderer
 * @texture: sdl texture
 */
void event_hand_io(SDL_Renderer *renderer, SDL_Texture *texture)
{
	for (int alpha = 0; alpha <= 255; alpha += 5)
	{
		SDL_SetTextureAlphaMod(texture, alpha);
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_RenderPresent(renderer);
		SDL_Delay(20);
	}
	SDL_Delay(1000);
	for (int alpha = 255; alpha >= 0; alpha -= 5)
	{
		SDL_SetTextureAlphaMod(texture, alpha);
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_RenderPresent(renderer);
		SDL_Delay(20);
	}
}
