#include "../headers/main.h"

/**
 * event_hand_ceil - rendering ceil
 * @renderer: sdl renderer
 * @text: sdl texture
 * @x: x coordinate
 * @y_start: start y coordinate
 * @screen_height: screen_hight
 * @skip: number of skipped lines
 */
void event_hand_ceil(SDL_Renderer *renderer, SDL_Texture **text,
		int x, int y_start, int screen_height, int skip)
{
	SDL_Rect src_rect = {x, 0, skip, y_start * 1280 / screen_height};
	SDL_Rect dst_rect = {x, 0, skip, y_start};

	SDL_RenderCopy(renderer, text[1], &src_rect, &dst_rect);
}
