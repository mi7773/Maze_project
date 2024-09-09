#include "../headers/main.h"

/**
 * event_hand_rain - rendering rain
 * @renderer: sdl renderer
 * @rain: rain drop
 * @screen_width: screen width
 * @rain_rate: rain rate
 */
void event_hand_rain(SDL_Renderer *renderer, rain_drop *rain, int screen_width,
		int rain_rate)
{
	SDL_SetRenderDrawColor(renderer, 135, 206, 235, 255);
	for (int i = 0; i < screen_width * rain_rate / 100; i++)
		SDL_RenderDrawLine(renderer, (int) rain[i].x, (int) rain[i].y,
				(int) (rain[i].x - rain_rate / 100),
				(int) (rain[i].y + rain_rate / 100));
}
