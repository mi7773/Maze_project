#include "../headers/main.h"

/**
 * event_hand_key - handling keyboard events
 * @running: true or false
 * @show_map: true or false
 * @show_rain: true or false
 * @map: 2d array representing map
 * @player_x: player x position
 * @player_y: player y position
 * @player_dir_x: player x direction
 * @player_dir_y: player y direction
 * @plane_x: plane x
 * @plane_y: plane y
 * @map_width: map width
 * @map_height: map height
 * @weapon: weapon index
 * @renderer: sdl renderer
 * @texture: sdl texture
 * @rain: rain drop
 * @screen_width: screen width
 * @screen_height: screen height
 * @rain_rate: rain rate
 */
void event_hand_key(bool *running, bool *show_map, bool *show_rain, int **map,
		float *player_x, float *player_y, float *player_dir_x, float *player_dir_y,
		float *plane_x, float *plane_y, int map_width, int map_height, int *weapon,
		SDL_Renderer *renderer, SDL_Texture *texture, rain_drop *rain,
		int screen_width, int screen_height, int *rain_rate)
{
	const Uint8 *state = SDL_GetKeyboardState(NULL);
	char dir[5] = "0000";
	int move = 0;
	float speed_amt = 0.1f;

	if (state[SDL_SCANCODE_W])
		dir[0] = 'w', move = 1;
	if (state[SDL_SCANCODE_S])
		dir[1] = 's', move = 1;
	if (state[SDL_SCANCODE_D])
		dir[2] = 'd', move = 1;
	if (state[SDL_SCANCODE_A])
		dir[3] = 'a', move = 1;
	if (state[SDL_SCANCODE_LSHIFT] && move == 1)
		speed_amt = 0.3f;
	if (move)
		event_hand_mov(dir, map, player_x, player_y, *player_dir_x, *player_dir_y,
				map_width, map_height, speed_amt);
	if (state[SDL_SCANCODE_Q])
		event_hand_rot(-0.1f, player_dir_x, player_dir_y, plane_x, plane_y);
	if (state[SDL_SCANCODE_E])
		event_hand_rot(0.1f, player_dir_x, player_dir_y, plane_x, plane_y);
	if (state[SDL_SCANCODE_M])
		*show_map = !(*show_map);
	if (state[SDL_SCANCODE_R])
	{
		*show_rain = !(*show_rain);
		if (*show_rain == true)
			event_hand_reset(rain, screen_width, screen_height, rain_rate);
	}
	if (state[SDL_SCANCODE_ESCAPE])
		event_hand_io(renderer, texture), *running = false;
	if (state[SDL_SCANCODE_1])
		*weapon = (*weapon < 6) ? 11 : *weapon - 1;
	if (state[SDL_SCANCODE_3])
		*weapon = (*weapon > 10) ? 5 : *weapon + 1;
}
