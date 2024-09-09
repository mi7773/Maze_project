#include "../headers/main.h"

/**
 * event_hand_mov - handling movement
 * @dir: direction
 * @map: 2d array representing map
 * @player_x: player x position
 * @player_y: player y position
 * @player_dir_x: player x direction
 * @player_dir_y: player y direction
 * @map_width: map width
 * @map_height: map height
 * @speed_amt: speed amount
 */
void event_hand_mov(char dir[5], int **map, float *player_x, float *player_y,
		float player_dir_x, float player_dir_y, int map_width, int map_height,
		float speed_amt)
{
	float new_player_x = *player_x, new_player_y = *player_y;
	int i = 0;

	while (dir[i] != '\0')
	{
		if (dir[i] == 'w')
		{
			new_player_x = *player_x + player_dir_x * speed_amt;
			new_player_y = *player_y + player_dir_y * speed_amt;
		}
		else if (dir[i] == 's')
		{
			new_player_x = *player_x - player_dir_x * speed_amt;
			new_player_y = *player_y - player_dir_y * speed_amt;
		}
		else if (dir[i] == 'd')
		{
			new_player_x = *player_x - player_dir_y * speed_amt;
			new_player_y = *player_y + player_dir_x * speed_amt;
		}
		else if (dir[i] == 'a')
		{
			new_player_x = *player_x + player_dir_y * speed_amt;
			new_player_y = *player_y - player_dir_x * speed_amt;
		}
		if ((int) new_player_x >= 0 && (int) new_player_y >= 0 &&
				(int) new_player_x <= map_width - 1 &&
				(int) new_player_y <= map_height - 1)
		{
			if (!map[(int) (new_player_y)][(int) (new_player_x)])
				*player_x = new_player_x, *player_y = new_player_y;
			else if (!map[(int) (new_player_y)][(int) (*player_x)])
				*player_y = new_player_y;
			else if (!map[(int) (*player_y)][(int) (new_player_x)])
				*player_x = new_player_x;
		}
		i++;
	}
}
