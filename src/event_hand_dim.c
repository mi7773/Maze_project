#include "../headers/main.h"

/**
 * event_hand_dim - calculating required dimensions
 * @side: 0 (vert.) or 1 (hor.)
 * @perp_wall_dist: perp. dist. bet. player and wall ray hits
 * @map_x: map x position
 * @map_y: map y position
 * @step_x: direction to move on map grid (+ve or -ve)
 * @step_y: direction to move on map grid (+ve or -ve)
 * @line_height: height of wall slice
 * @player_x: player x position
 * @player_y: player y position
 * @ray_dir_x: ray x direction
 * @ray_dir_y: ray y direction
 * @screen_height: screen height
 * @y_start: start y coordinate
 * @y_end: end y coordinate
 */
void event_hand_dim(int side, float *perp_wall_dist, int map_x, int map_y,
		int step_x, int step_y, int *line_height, float player_x, float player_y,
		float ray_dir_x, float ray_dir_y, int screen_height,
		int *y_start, int *y_end)
{
	if (side == 0)
		*perp_wall_dist = (map_x - player_x + (1 - step_x) / 2) / ray_dir_x;
	else
		*perp_wall_dist = (map_y - player_y + (1 - step_y) / 2) / ray_dir_y;
	*line_height = (int) (screen_height / *perp_wall_dist);
	*y_start = -*line_height / 2 + screen_height / 2;
	if (*y_start < 0)
		*y_start = 0;
	*y_end = *line_height / 2 + screen_height / 2;
	if (*y_end >= screen_height)
		*y_end = screen_height - 1;
}
