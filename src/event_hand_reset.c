#include "../headers/main.h"

/**
 * event_hand_reset - resetting
 * @rain: rain dropo
 * @screen_width: screen width
 * @screen_height: screen height
 * @rain_rate: rain rate
 */
void event_hand_reset(rain_drop *rain, int screen_width, int screen_height,
		int *rain_rate)
{
	*rain_rate = 50;
	for (int i = 0; i < screen_width * 6; i++)
	{
		rain[i].x = rand() % screen_width;
		rain[i].y = rand() % screen_height;
		rain[i].s = rand() % 3 + 2;
	}
}
