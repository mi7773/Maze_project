#include "../headers/main.h"

/**
 * event_hand_weapon - rendering weapon
 * @renderer: sdl renderer
 * @screen_width: screen width
 * @screen_height: screen height
 * @weapon: weapon index
 * @text: array of pointers to sdl texture
 */
void event_hand_weapon(SDL_Renderer *renderer,
		int screen_width, int screen_height,
		int weapon, SDL_Texture **text)
{
	SDL_Rect dst_rect = {screen_width / 4, screen_height / 2,
		screen_width / 2, screen_height / 2};
	SDL_RenderCopy(renderer, text[weapon], NULL, &dst_rect);
}
