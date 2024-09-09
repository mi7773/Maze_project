#include "../headers/main.h"

/**
 * event_hand_mouse - handling mouse events
 * @event: sdl event
 * @player_dir_x: player x direction
 * @player_dir_y: player y direction
 * @plane_x: plane x
 * @plane_y: plane y
 */
void event_hand_mouse(SDL_Event event,
		float *player_dir_x, float *player_dir_y, float *plane_x, float *plane_y)
{
	float sensitivity = 0.005f;
	float rot_amt = (float) (sensitivity * event.motion.xrel);

	if (rot_amt != 0)
		event_hand_rot(rot_amt, player_dir_x, player_dir_y, plane_x, plane_y);
}
