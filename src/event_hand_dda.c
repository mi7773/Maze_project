#include "../headers/main.h"

/**
 * event_hand_dda - handling digital differential analysis
 * @hit: 0 (empty) or 1 (wall)
 * @side: 0 (vert.) or 1 (hor.)
 * @map_x: map x position
 * @map_y: map y position
 * @step_x: direction to move on map grid (+ve or -ve)
 * @step_y: direction to move on map grid (+ve or -ve)
 * @side_dist_x: dist. from player pos. to next vert. grid line
 * @side_dist_y: dist. from player pos. to next hor. grid line
 * @delta_dist_x: x dist. ray must travel to move from one grid line to next
 * @delta_dist_y: y dist. ray must travel to move from one grid line to next
 * @map: 2d array representing map
 */
void event_hand_dda(int *hit, int *side, int *map_x, int *map_y,
		int step_x, int step_y, float *side_dist_x, float *side_dist_y,
		float delta_dist_x, float delta_dist_y, int **map)
{

	while (*hit == 0)
	{
		if (*side_dist_x < *side_dist_y)
		{
			*side_dist_x += delta_dist_x;
			*map_x += step_x;
			*side = 0;
		}
		else
		{
			*side_dist_y += delta_dist_y;
			*map_y += step_y;
			*side = 1;
		}
		if (map[*map_y][*map_x] > 0)
			*hit = 1;
	}
}
