#include "../headers/main.h"

/**
 * map_hand_col_num - finding number of cols
 * @fp: file pointer
 * @map_width: number of cols
 */
void map_hand_col_num(FILE *fp, int *map_width)
{
	char c;

	do {
		c = fgetc(fp);
		*map_width = *map_width + 1;
	} while (c != '\n');
	fseek(fp, 0, SEEK_SET);
}
