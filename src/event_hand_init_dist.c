#include "../headers/main.h"

/**
 * event_hand_init_dist - calculating the initial distance
 * to the nearest grid line
 * @ray_dir_x: ray x direction
 * @ray_dir_y: ray y direction
 * @map_x: map x position
 * @map_y: map y position
 * @side_dist_x: dist. from player pos. to next vert. grid line
 * @side_dist_y: dist. from player pos. to next hor. grid line
 * @step_x: direction to move on map grid (+ve or -ve)
 * @step_y: direction to move on map grid (+ve or -ve)
 * @delta_dist_x: x dist. ray must travel to move from one grid line to next
 * @delta_dist_y: y dist. ray must travel to move from one grid line to next
 * @player_x: player x position
 * @player_y: player y position
 */
void event_hand_init_dist(float ray_dir_x, float ray_dir_y,
		int map_x, int map_y, float *side_dist_x, float *side_dist_y,
		int *step_x, int *step_y, float delta_dist_x, float delta_dist_y,
		float player_x, float player_y)
{
	if (ray_dir_x < 0)
	{
		*step_x = -1;
		*side_dist_x = (player_x - map_x) * delta_dist_x;
	}
	else
	{
		*step_x = 1;
		*side_dist_x = (map_x + 1.0 - player_x) * delta_dist_x;
	}
	if (ray_dir_y < 0)
	{
		*step_y = -1;
		*side_dist_y = (player_y - map_y) * delta_dist_y;
	}
	else
	{
		*step_y = 1;
		*side_dist_y = (map_y + 1.0 - player_y) * delta_dist_y;
	}
}
