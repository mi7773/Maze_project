#include "../headers/main.h"

/**
 * map_hand_close_file - closing files
 * @fp: file pointer
 * @path: file path
 * Return: 0 (success), or 1 (error)
 */
int map_hand_close_file(FILE *fp, char *path)
{
	int c = fclose(fp);

	if (c != 0)
	{
		fprintf(stderr, "Error: Can't close file: %s\n", path);
		return (1);
	}
	return (0);
}
