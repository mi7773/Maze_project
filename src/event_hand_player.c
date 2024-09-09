#include "../headers/main.h"

/**
 * event_hand_player - drawing on map
 * @screen_height: screen height
 * @map_height: map height
 * @player_x: player x position
 * @player_y: player y position
 * @player_dir_x: player x direction
 * @player_dir_y: player y direction
 * @renderer: sdl renderer
 */
void event_hand_player(int screen_height, int map_height,
		float player_x, float player_y, float player_dir_x, float player_dir_y,
		SDL_Renderer *renderer)
{
	SDL_Rect player;
	int tile_size = 4, n = 1;
	int shift_x = (tile_size * 5);
	int shift_y = (screen_height - map_height * tile_size) - (tile_size * 5);
	float x0, y0, x1, y1;

	player.x = player_x * tile_size + shift_x;
	player.y = player_y * tile_size + shift_y;
	player.w = tile_size, player.h = tile_size;
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(renderer, &player);
	while (n >= -1)
	{
		x0 = player_x * tile_size + 3 * player_dir_x * tile_size + shift_x + n;
		y0 = player_y * tile_size + 3 * player_dir_y * tile_size + shift_y;
		x1 = player_x * tile_size + shift_x + n;
		y1 = player_y * tile_size + shift_y;
		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
		SDL_RenderDrawLine(renderer, x0, y0, x1, y1);
		n--;
	}
}
