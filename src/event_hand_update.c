#include "../headers/main.h"

/**
 * event_hand_update - updating
 * @rain: rain drop
 * @screen_width: screen width
 * @screen_height: screen height
 * @rain_rate: rain rate
 * @show_rain: true or false
 */
void event_hand_update(rain_drop *rain, int screen_width, int screen_height,
		int *rain_rate, bool show_rain)
{
	if (show_rain)
		*rain_rate = (*rain_rate < 300) ? *rain_rate + 1 : *rain_rate;
	else
		*rain_rate = (*rain_rate > 0) ? *rain_rate - 1 : *rain_rate;
	for (int i = 0; i < screen_width * *rain_rate / 100; i++)
	{
		rain[i].y += rain[i].s * *rain_rate / 100;
		rain[i].x -= rain[i].s * *rain_rate / 100;
		if (rain[i].y > screen_height)
		{
			rain[i].y = -1;
		}
		if (rain[i].x < 0)
		{
			rain[i].x = screen_width;
		}
	}
}
