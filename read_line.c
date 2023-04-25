#include "main.h"

/**
 * read_line - read user input line
 * Return: pointer to the input line
 */

char *read_line()
{
	size_t length;
	char *line;
	int is_read;
	int space_check;

	line = NULL;
	length = 0;
	is_read = getline(&line, &length, stdin);
	if (is_read == -1)
	{
		if (errno == 0)
		{
			exit(0);
		}
		free(line);
		return (NULL);
	}
	space_check = is_space(line);
	if (space_check == 0)
	{
		exit(0);
	}

	return (line);
}
