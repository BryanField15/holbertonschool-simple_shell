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

	line = NULL;
	length = 0;
	is_read = getline(&line, &length, stdin);
	if (is_read == -1 && errno == 0)
	{
		exit(0);
	}
	else if (is_read == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
