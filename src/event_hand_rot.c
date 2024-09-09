#include "../headers/main.h"

/**
 * event_hand_rot - handling rotation
 * @rot_amt: rotation amount
 * @player_dir_x: player x direction
 * @player_dir_y: player y direction
 * @plane_x: plane x
 * @plane_y: plane y
 */
void event_hand_rot(float rot_amt, float *player_dir_x, float *player_dir_y,
		float *plane_x, float *plane_y)
{
	float old_player_dir_x = *player_dir_x, old_plane_x = *plane_x;

	*player_dir_x = *player_dir_x * cos(rot_amt) - *player_dir_y * sin(rot_amt);
	*player_dir_y = old_player_dir_x * sin(rot_amt) +
		*player_dir_y * cos(rot_amt);
	*plane_x = *plane_x * cos(rot_amt) - *plane_y * sin(rot_amt);
	*plane_y = old_plane_x * sin(rot_amt) + *plane_y * cos(rot_amt);
}
