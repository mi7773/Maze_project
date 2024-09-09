#include "../headers/main.h"

/**
 * map_hand_row_num - finding number of rows
 * @fp: file pointer
 * @map_height: number of rows
 */
void map_hand_row_num(FILE *fp, int *map_height)
{
	char c;

	do {
		c = fgetc(fp);
		*map_height = (c == '\n') ? (*map_height + 1) : (*map_height);
	} while (c != -1);
	fseek(fp, 0, SEEK_SET);
}
