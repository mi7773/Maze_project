#include "../headers/main.h"

/**
 * event_hand_ground - rendering ground
 * @screen_width: screen width
 * @screen_height: screen height
 * @skip: number of skipped lines
 * @player_dir_x: player x direction
 * @player_dir_y: player y direction
 * @plane_x: plane x
 * @plane_y: plane y
 * @player_x: player x position
 * @player_y: player y position
 * @renderer: sdl renderer
 * @text: array of pointers to sdl texture
 * @tile_size: tile size
 */
void event_hand_ground(int screen_width, int screen_height, int skip,
		float player_dir_x, float player_dir_y, float plane_x, float plane_y,
		float player_x, float player_y, int tile_size,
		SDL_Renderer *renderer, SDL_Texture **text)
{
	float ray_dir_x0, ray_dir_x1, ray_dir_y0, ray_dir_y1, brt;
	float pos_z, row_distance, floor_step_x, floor_step_y, floor_x, floor_y;
	int p, text_x, text_y;
	SDL_Rect src_rect, dst_rect;

	for (int y = screen_height / 2; y < screen_height; y += skip)
	{
		ray_dir_x0 = player_dir_x - plane_x;
		ray_dir_x1 = player_dir_x + plane_x;
		ray_dir_y0 = player_dir_y - plane_y;
		ray_dir_y1 = player_dir_y + plane_y;
		p = y - screen_height / 2;
		pos_z = 0.5 * screen_height;
		row_distance = pos_z / p;
		floor_step_x = row_distance * (ray_dir_x1 - ray_dir_x0) / screen_width;
		floor_step_y = row_distance * (ray_dir_y1 - ray_dir_y0) / screen_width;
		floor_x = player_x + row_distance * ray_dir_x0;
		floor_y = player_y + row_distance * ray_dir_y0;
		brt = 1.0f / (row_distance * 0.2f + 0.5f);
		brt = (brt > 1.0f) ? 1.0f : brt;
		SDL_SetTextureColorMod(text[3], 255 * brt, 255 * brt, 255 * brt);
		for (int x = 0; x < screen_width; x += skip)
		{
			text_x = (int) (tile_size * (floor_x - (int) (floor_x))) & (tile_size - 1);
			text_y = (int) (tile_size * (floor_y - (int) (floor_y))) & (tile_size - 1);
			src_rect.x = text_x, src_rect.y = text_y;
			src_rect.w = skip, src_rect.h = skip;
			dst_rect.x = x, dst_rect.y = y;
			dst_rect.w = skip, dst_rect.h = skip;
			SDL_RenderCopy(renderer, text[3], &src_rect, &dst_rect);
			floor_x += floor_step_x * skip;
			floor_y += floor_step_y * skip;
		}
	}
}
