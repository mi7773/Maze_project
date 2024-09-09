#include "../headers/main.h"

/**
 * map_hand - handling map processes
 * @argc: number of command-line arguments
 * @argv: array of character pointers listing all the arguments
 * @map_width: map width
 * @map_height: map height
 * @player_x: player x position
 * @player_y: player y position
 * Return: 2d array representing map
 * @enemies: enemies
 */
int **map_hand(int argc, char *argv[],
		int *map_width, int *map_height, float *player_x, float *player_y,
		enemy *enemies)
{
	char *path = "maps/map2.txt";
	FILE *fp = NULL;
	int **map = NULL;

	path = (argc < 2) ? path : argv[1];
	if (map_hand_open_file(path, &fp) == 1)
		return (NULL);
	map_hand_col_num(fp, map_width);
	map_hand_row_num(fp, map_height);
	map = map_hand_malloc(fp, path, *map_width, *map_height);
	if (map == NULL)
		return (NULL);
	if (map_hand_close_file(fp, path) == 1)
		return (NULL);
	map_hand_pos(map, player_x, player_y, enemies);
	return (map);
}
