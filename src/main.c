#include "../headers/main.h"

/**
 * main - entering program
 * @argc: number of command-line arguments
 * @argv: array of character pointers listing all the arguments
 * Return: 0 (success), or 1 (error)
 */
int main(int argc, char *argv[])
{
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;
	SDL_Texture **text = NULL;
	int screen_width = 1280, screen_height = 720;
	int map_width = -1, map_height = 0, **map = NULL;
	float player_x, player_y, player_dir_x = 1.0f, player_dir_y = 0.0f;
	float plane_x = 0.0f, plane_y = 0.66f;
	enemy enemies[3];

	text = sdl_hand(&window, &renderer, screen_width, screen_height);
	if (text == NULL)
		return (1);
	map = map_hand(argc, argv, &map_width, &map_height, &player_x, &player_y,
			enemies);
	if (map == NULL)
		return (1);
	event_hand(renderer, screen_width, screen_height, map,
			map_width, map_height, &player_x, &player_y,
			&player_dir_x, &player_dir_y, &plane_x, &plane_y, text, enemies);
	sdl_close(&window, &renderer, text);
	map_free(map, map_height);
	return (0);
}
