#include "../headers/main.h"

/**
 * map_hand_open_file - opening files
 * @path: file path
 * @fp: file pointer
 * Return: 0 (success), or 1 (error)
 */
int map_hand_open_file(char *path, FILE **fp)
{
	*fp = fopen(path, "r");
	if (*fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file: %s\n", path);
		return (1);
	}
	return (0);
}
