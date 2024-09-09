#include "../headers/main.h"

/**
 * event_hand - handling events
 * @renderer: sdl renderer
 * @screen_width: screen width
 * @screen_height: screen height
 * @map: 2d array representing map
 * @map_width: map width
 * @map_height: map height
 * @player_x: player x position
 * @player_y: player y position
 * @player_dir_x: player x direction
 * @player_dir_y: player y direction
 * @plane_x: plane x
 * @plane_y: plane y
 * @text: array of pointers to sdl texture
 * @enemies: enemies
 */
void event_hand(SDL_Renderer *renderer, int screen_width, int screen_height,
		int **map, int map_width, int map_height, float *player_x, float *player_y,
		float *player_dir_x, float *player_dir_y, float *plane_x, float *plane_y,
		SDL_Texture **text, enemy *enemies)
{
	bool running = true, show_map = false, show_rain = false;
	SDL_Event event;
	int weapon = 11, rain_rate = 0;
	rain_drop rain[screen_width * 300];

	event_hand_io(renderer, text[0]);
	while (running)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				event_hand_io(renderer, text[0]), running = false;
			if (event.type == SDL_KEYDOWN)
				event_hand_key(&running, &show_map, &show_rain, map, player_x, player_y,
						player_dir_x, player_dir_y, plane_x, plane_y, map_width,
						map_height, &weapon, renderer, text[0], rain,
						screen_width, screen_height, &rain_rate);
			if (event.type == SDL_MOUSEMOTION)
				event_hand_mouse(event, player_dir_x, player_dir_y, plane_x, plane_y);
		}
		if (running)
		{
			if (rain_rate)
				event_hand_update(rain, screen_width, screen_height, &rain_rate,
						show_rain);
			event_hand_graph(renderer, show_map, screen_width, screen_height,
					map, *player_x, *player_y, *player_dir_x, *player_dir_y,
					*plane_x, *plane_y, map_width, map_height, text, weapon,
					rain, rain_rate, enemies);
		}
	}
}
