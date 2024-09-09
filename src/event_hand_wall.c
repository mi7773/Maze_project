#include "../headers/main.h"

/**
 * event_hand_wall - rendering wall
 * @renderer: sdl renderer
 * @x: x coordinate
 * @y_start: start y coordinate
 * @y_end: end y coordinate
 * @side: 0 (vert.) or 1 (hor.)
 * @text: array of pointers to sdl texture
 * @screen_height: screen height
 * @line_height: height of wall slice
 * @tile_size: tile size
 * @player_x: player x position
 * @player_y: player y position
 * @perp_wall_dist: perp. dist. bet. player and wall ray hits
 * @ray_dir_x: ray x direction
 * @ray_dir_y: ray y direction
 * @skip: number of skipped lines
 */
void event_hand_wall(SDL_Renderer *renderer, int x, int y_start, int y_end,
		int side, SDL_Texture **text, int screen_height, int line_height,
		int tile_size, float player_x, float player_y, float perp_wall_dist,
		float ray_dir_x, float ray_dir_y, int skip)
{
	SDL_Rect src_rect, dst_rect;
	int text_y_start, text_y_end, text_x, height;
	float wall_x, brt = 1.0f / (perp_wall_dist * 0.5f + 0.1f);

	brt = (brt > 1.0f) ? 1.0f : brt;
	line_height = (line_height > screen_height) ? screen_height : line_height;
	text_y_start = (((y_start * 256 - screen_height * 128 +
					line_height * 128) * tile_size) / line_height) / 256;
	text_y_end = (((y_end * 256 - screen_height * 128 +
					line_height * 128) * tile_size) / line_height) / 256;
	height = text_y_end - text_y_start;
	if (side == 1)
		SDL_SetTextureColorMod(text[2], 125 * brt, 125 * brt, 125 * brt),
			wall_x = player_x + perp_wall_dist * ray_dir_x;
	else
		SDL_SetTextureColorMod(text[2], 255 * brt, 255 * brt, 255 * brt),
			wall_x = player_y + perp_wall_dist * ray_dir_y;
	wall_x -= floor(wall_x);
	text_x = (int) (wall_x * (float) tile_size);
	if ((side == 0 && ray_dir_x > 0) || (side == 1 && ray_dir_y < 0))
		text_x = tile_size - text_x - 1;
	src_rect.x = text_x, src_rect.y = text_y_start;
	src_rect.w = skip, src_rect.h = height;
	dst_rect.x = x, dst_rect.y = y_start;
	dst_rect.w = skip, dst_rect.h = y_end - y_start;
	SDL_RenderCopy(renderer, text[2], &src_rect, &dst_rect);
}
