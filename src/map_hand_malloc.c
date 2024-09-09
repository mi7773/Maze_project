#include "../headers/main.h"

/**
 * map_hand_malloc - handling malloc process
 * @fp: file pointer
 * @path: file path
 * @map_width: map width
 * @map_height: map height
 * Return: 2d array representing map
 */
int **map_hand_malloc(FILE *fp, char *path, int map_width, int map_height)
{
	int i = 0, j = 0, k = 0, val, **map = NULL;
	char c;

	map = (int **) malloc(map_height * sizeof(int *));
	if (map == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		return (NULL);
	}
	while (i < map_height)
	{
		map[i] = (int *) malloc(map_width * sizeof(int));
		if (map[i] == NULL)
		{
			fprintf(stderr, "Memory allocation failed\n");
			while (j < i)
			{
				free(map[j]);
				j++;
			}
			free(map);
			return (NULL);
		}
		k = 0, c = fgetc(fp);
		while (c != '\n')
		{
			val = c - '0';
			if ((val == 0 || val == 1))
				map[i][k] = val;
			else
			{
				fprintf(stderr, "Invalid map file: %s\n", path);
				return (NULL);
			}
			c = fgetc(fp), k++;
		}
		i++;
	}
	return (map);
}
