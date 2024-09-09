#include "../headers/main.h"

/**
 * map_free - freeing map
 * @map: 2d array representing map
 * @map_height: map height
 */
void map_free(int **map, int map_height)
{
	int i = 0;

	while (i < map_height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
