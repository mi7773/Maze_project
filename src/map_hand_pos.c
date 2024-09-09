#include "../headers/main.h"

/**
 * map_hand_pos - handling positions
 * @map: 2d array representing map
 * @player_x: player x position
 * @player_y: player y position
 * @enemies: enemies
 */
void map_hand_pos(int **map, float *player_x, float *player_y, enemy *enemies)
{
	*player_x = *player_y = 0.5f;
	while (1)
	{
		if (map[(int) *player_y][(int) *player_x])
			*player_x = *player_x + 1, *player_y = *player_y + 1;
		else
			break;
	}
	for (int i = 0; i < 3; i++)
	{
		enemies[i].x = 15.5f + i * 13, enemies[i].y = 15.5f + i * 12;
		while (1)
		{
			if (map[(int) enemies[i].y][(int) enemies[i].x])
				enemies[i].x = enemies[i].x + 1, enemies[i].y = enemies[i].y + 1;
			else
				break;
		}
	}
}
