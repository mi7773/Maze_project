#include "../headers/main.h"

/**
* event_hand_enemy - rendering enemies
* @enemies: enemies
* @player_x: player x position
* @player_y: player y position
* @plane_x: plane x
* @plane_y: plane y
* @player_dir_x: player x direction
* @player_dir_y: player y direction
* @screen_width: screen width
* @screen_height: screen height
* @tile_size: tile_size
* @renderer: sdl renderer
* @text: sdl texture
* @depth: depth
*/
void event_hand_enemy(enemy *enemies, float player_x, float player_y,
	float plane_x, float plane_y, float player_dir_x, float player_dir_y,
	int screen_width, int screen_height, int tile_size,
	SDL_Renderer *renderer, SDL_Texture **text, float *depth)
{
	float sprite_x, sprite_y, inv_det, transform_x, transform_y, brt;
	int sprite_screen_x, sprite_width, sprite_height;
	int x_start, x_end, y_start, y_end, text_x;

	for (int i = 0; i < 3; i++)
	{sprite_x = enemies[i].x - player_x, sprite_y = enemies[i].y - player_y;
		inv_det = 1.0 / (plane_x * player_dir_y - plane_y * player_dir_x);
		transform_x = inv_det * (player_dir_y * sprite_x - player_dir_x * sprite_y);
		transform_y = inv_det * (-plane_y * sprite_x + plane_x * sprite_y);
		brt = 1.0f / (transform_y * 0.2f + 0.5f), brt = (brt > 1.0f) ? 1.0f : brt;
		SDL_SetTextureColorMod(text[4], 255 * brt, 255 * brt, 255 * brt);
		if (transform_y <= 0)
			continue;
		sprite_screen_x = (int) ((screen_width / 2) *
				(1 + transform_x / transform_y));
		sprite_width = abs((int) (screen_height / transform_y));
		x_start = -sprite_width / 2 + sprite_screen_x;
		x_start = (x_start < 0) ? 0 : x_start;
		x_end = sprite_width / 2 + sprite_screen_x;
		x_end = (x_end > screen_width) ? screen_width - 1 : x_end;
		sprite_height = abs((int) (screen_height / transform_y));
		y_start = -sprite_height / 2 + screen_height / 2;
		y_start = (y_start < 0) ? 0 : y_start;
		y_end = sprite_height / 2 + screen_height / 2;
		y_end = (y_end > screen_width) ? screen_height - 1 : y_end;
		for (int x = x_start; x <= x_end; x += 4)
		{
			if (x >= 0 && x <= screen_width - 1)
			{
				if (transform_y < depth[x])
				{text_x = (int) ((256 * (x - (-sprite_width / 2 + sprite_screen_x)) *
							tile_size / sprite_width) / 256);
					for (int y = y_start; y <= y_end; y += 4)
					{int text_y = (((y * 256 - screen_height * 128 + sprite_height * 128) *
								tile_size) / sprite_height) / 256;
					SDL_Rect src_rect = {text_x, text_y, 4, 4}, dst_rect = {x, y, 4, 4};

					SDL_RenderCopy(renderer, text[4], &src_rect, &dst_rect);
					}}}}}
}
