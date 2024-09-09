#ifndef MAIN_H
#define MAIN_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * struct rain_drop - rain drop
 * @x: rain drop x position
 * @y: rain drop y position
 * @s: rain drop speed
 */
typedef struct rain_drop
{
	float x, y, s;
} rain_drop;
/**
 * struct enemy - enemy
 * @x: enemy x position
 * @y: enemy y position
 */
typedef struct enemy
{
	float x, y;
} enemy;

int main(int argc, char *argv[]);
SDL_Texture **sdl_hand(SDL_Window **window, SDL_Renderer **renderer,
		int screen_width, int screen_height);
int sdl_hand_wind(SDL_Window **window, int screen_width, int screen_height);
int sdl_hand_rend(SDL_Window **window, SDL_Renderer **renderer);
SDL_Texture **sdl_hand_malloc(void);
int sdl_hand_surf(SDL_Window **window, SDL_Renderer **renderer,
		SDL_Surface **loaded_surface, char *path);
int sdl_hand_text(SDL_Window **window, SDL_Renderer **renderer,
		SDL_Surface **loaded_surface, SDL_Texture **texture);

int **map_hand(int argc, char *argv[],
		int *map_width, int *map_height, float *player_x, float *player_y,
		enemy *enemies);
int map_hand_open_file(char *path, FILE **fp);
void map_hand_col_num(FILE *fp, int *map_width);
void map_hand_row_num(FILE *fp, int *map_height);
int **map_hand_malloc(FILE *fp, char *path, int map_width, int map_height);
void map_hand_pos(int **map, float *player_x, float *player_y, enemy *enemies);
int map_hand_close_file(FILE *fp, char *path);

void event_hand(SDL_Renderer *renderer, int screen_width, int screen_height,
		int **map, int map_width, int map_height, float *player_x, float *player_y,
		float *player_dir_x, float *player_dir_y, float *plane_x, float *plane_y,
		SDL_Texture **text, enemy *enemies);
void event_hand_io(SDL_Renderer *renderer, SDL_Texture *texture);
void event_hand_key(bool *running, bool *show_map, bool *show_rainn, int **map,
		float *player_x, float *player_y, float *player_dir_x, float *player_dir_y,
		float *plane_x, float *plane_y, int map_width, int map_height, int *weapon,
		SDL_Renderer *renderer, SDL_Texture *texture, rain_drop *rain,
		int screen_width, int screen_height, int *rain_rate);
void event_hand_mouse(SDL_Event event,
		float *player_dir_x, float *player_dir_y, float *plane_x, float *plane_y);
void event_hand_mov(char dir[5], int **map, float *player_x, float *player_y,
		float player_dir_x, float player_dir_y, int map_width, int map_height,
		float speed_amt);
void event_hand_rot(float rot_amt, float *player_dir_x, float *player_dir_y,
		float *plane_x, float *plane_y);
void event_hand_reset(rain_drop *rain, int screen_width, int screen_height,
		int *rain_rate);
void event_hand_update(rain_drop *rain, int screen_width, int screen_height,
		int *rain_rate, bool show_rain);
void event_hand_graph(SDL_Renderer *renderer, bool show_map,
		int screen_width, int screen_height, int **map,
		float player_x, float player_y, float player_dir_x, float player_dir_y,
		float plane_x, float plane_y, int map_width, int map_height,
		SDL_Texture **text, int weapon, rain_drop *rain, int rain_rate,
		enemy *enemies);
void event_hand_ray(SDL_Renderer *renderer,
		int screen_width, int screen_height, int **map,
		float player_x, float player_y, float player_dir_x, float player_dir_y,
		float plane_x, float plane_y, SDL_Texture **text, int tile_size,
		float *depth);
void event_hand_init_dist(float ray_dir_x, float ray_dir_y,
		int map_x, int map_y, float *side_dist_x, float *side_dist_y,
		int *step_x, int *step_y, float delta_dist_x, float delta_dist_y,
		float player_x, float player_y);
void event_hand_dda(int *hit, int *side, int *map_x, int *map_y,
		int step_x, int step_y, float *side_dist_x, float *side_dist_y,
		float delta_dist_x, float delta_dist_y, int **map);
void event_hand_dim(int side, float *perp_wall_dist, int map_x, int map_y,
		int step_x, int step_y, int *line_height, float player_x, float player_y,
		float ray_dir_x, float ray_dir_y, int screen_height,
		int *y_start, int *y_end);
void event_hand_ground(int screen_width, int screen_height, int skip,
		float player_dir_x, float player_dir_y, float plane_x, float plane_y,
		float player_x, float player_y, int tile_size,
		SDL_Renderer *renderer, SDL_Texture **text);
void event_hand_ceil(SDL_Renderer *renderer, SDL_Texture **text,
		int x, int y_start, int screen_height, int skip);
void event_hand_wall(SDL_Renderer *renderer, int x, int y_start, int y_end,
		int side, SDL_Texture **text, int screen_height, int line_height,
		int tile_size, float player_x, float player_y, float perp_wall_dist,
		float ray_dir_x, float ray_dir_y, int skip);
void event_hand_weapon(SDL_Renderer *renderer,
		int screen_width, int screen_height, int weapon, SDL_Texture **text);
void event_hand_enemy(enemy *enemies, float player_x, float player_y,
		float plane_x, float plane_y, float player_dir_x, float player_dir_y,
		int screen_width, int screen_height, int tile_size,
		SDL_Renderer *renderer, SDL_Texture **text, float *depth);
void event_hand_rain(SDL_Renderer *renderer, rain_drop *rain,
		int screen_width, int rain_rate);
void event_hand_map(int map_width, int map_height, int screen_height,
		int **map, SDL_Renderer *renderer);
void event_hand_player(int screen_height, int map_height,
		float player_x, float player_y, float player_dir_x, float player_dir_y,
		SDL_Renderer *renderer);
void sdl_close(SDL_Window **window, SDL_Renderer **renderer,
		SDL_Texture **text);
void map_free(int **map, int map_height);

#endif  /* MAIN_H */
