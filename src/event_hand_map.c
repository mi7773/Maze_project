#include "../headers/main.h"

/**
 * event_hand_map - drawing map
 * @map_width: map width
 * @map_height: map height
 * @screen_height: screen height
 * @map: 2d array representing map
 * @renderer: sdl renderer
 */
void event_hand_map(int map_width, int map_height, int screen_height,
		int **map, SDL_Renderer *renderer)
{
	for (int x = 0; x < map_width; x++)
	{
		for (int y = 0; y < map_height; y++)
		{
			SDL_Rect tile;
			int tile_size = 4;
			int shift_x = tile_size * 5;
			int shift_y = (screen_height - map_height * tile_size) - (tile_size * 5);

			tile.x = x * tile_size + shift_x;
			tile.y = y * tile_size + shift_y;
			tile.w = tile_size;
			tile.h = tile_size;
			if (map[y][x] == 1)
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			else if (map[y][x] == 0)
				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			SDL_RenderFillRect(renderer, &tile);
		}
	}
}
