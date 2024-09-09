#include "../headers/main.h"

/**
 * event_hand_graph - handling graphics
 * @renderer: sdl renderer
 * @show_map: true or false
 * @screen_width: screen width
 * @screen_height: screen height
 * @map: 2d array representing map
 * @player_x: player x position
 * @player_y: player y position
 * @player_dir_x: player x direction
 * @player_dir_y: player y direction
 * @plane_x: plane x
 * @plane_y: plane y
 * @map_width: map width
 * @map_height: map height
 * @text: array of pointers to sdl texture
 * @weapon: weapon index
 * @rain: rain drop
 * @rain_rate: rain rate
 * @enemies: enemies
 */
void event_hand_graph(SDL_Renderer *renderer, bool show_map,
		int screen_width, int screen_height, int **map,
		float player_x, float player_y, float player_dir_x, float player_dir_y,
		float plane_x, float plane_y, int map_width, int map_height,
		SDL_Texture **text, int weapon, rain_drop *rain, int rain_rate,
		enemy *enemies)
{
	int tile_size = 1024;
	float depth[screen_width];

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	event_hand_ray(renderer, screen_width, screen_height, map, player_x, player_y,
			player_dir_x, player_dir_y, plane_x, plane_y, text, tile_size, depth);
	event_hand_enemy(enemies, player_x, player_y, plane_x, plane_y,
			player_dir_x, player_dir_y, screen_width, screen_height, tile_size,
			renderer, text, depth);
	event_hand_weapon(renderer, screen_width, screen_height, weapon, text);
	if (rain_rate)
		event_hand_rain(renderer, rain, screen_width, rain_rate);
	if (show_map)
		event_hand_map(map_width, map_height, screen_height, map, renderer),
			event_hand_player(screen_height, map_height, player_x, player_y,
				player_dir_x, player_dir_y, renderer);
	SDL_RenderPresent(renderer);
}
