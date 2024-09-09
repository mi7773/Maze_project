#include "../headers/main.h"

/**
 * event_hand_ray - handling rays
 * @renderer: sdl renderer
 * @screen_width: screen width
 * @screen_height: screen height
 * @map: 2d array representing map
 * @player_x: player x position
 * @player_y: player y position
 * @player_dir_x: player x direction
 * @player_dir_y: player y direction
 * @plane_x: plane x
 * @plane_y: plane y
 * @text: array of pointers to sdl texture
 * @tile_size: tile size
 * @depth: depth
 */
void event_hand_ray(SDL_Renderer *renderer,
		int screen_width, int screen_height, int **map,
		float player_x, float player_y, float player_dir_x, float player_dir_y,
		float plane_x, float plane_y, SDL_Texture **text, int tile_size,
		float *depth)
{
	float camera_x, ray_dir_x, ray_dir_y, side_dist_x, side_dist_y;
	float delta_dist_x, delta_dist_y, perp_wall_dist;
	int map_x, map_y, step_x, step_y, hit, side, line_height, y_start, y_end;
	int skip = 1;

	event_hand_ground(screen_width, screen_height, skip * 4,
			player_dir_x, player_dir_y, plane_x, plane_y, player_x, player_y,
			tile_size, renderer, text);
	for (int x = 0; x < screen_width; x += skip)
	{
		camera_x = 2 * x / (float) screen_width - 1;
		ray_dir_x = player_dir_x + plane_x * camera_x;
		ray_dir_y = player_dir_y + plane_y * camera_x;
		map_x = (int) player_x, map_y = (int) player_y, hit = 0;
		delta_dist_x = fabs(1 / ray_dir_x), delta_dist_y = fabs(1 / ray_dir_y);
		event_hand_init_dist(ray_dir_x, ray_dir_y, map_x, map_y,
				&side_dist_x, &side_dist_y, &step_x, &step_y,
				delta_dist_x, delta_dist_y, player_x, player_y);
		event_hand_dda(&hit, &side, &map_x, &map_y, step_x, step_y,
				&side_dist_x, &side_dist_y, delta_dist_x, delta_dist_y, map);
		event_hand_dim(side, &perp_wall_dist, map_x, map_y, step_x, step_y,
				&line_height, player_x, player_y, ray_dir_x, ray_dir_y, screen_height,
				&y_start, &y_end);
		event_hand_ceil(renderer, text, x, y_start, screen_height, skip);
		event_hand_wall(renderer, x, y_start, y_end, side, text,
				screen_height, line_height, tile_size, player_x, player_y,
				perp_wall_dist, ray_dir_x, ray_dir_y, skip);
		depth[x] = perp_wall_dist;
	}
}
