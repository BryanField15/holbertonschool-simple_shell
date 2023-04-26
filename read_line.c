#include "main.h"

/**
 * read_line - read user input line
 * Return: pointer to the input line
 */

char *read_line()
{
	size_t length;
	char *line;
	ssize_t is_read;

	line = NULL;
	length = 0;
	is_read = getline(&line, &length, stdin);
	printf("Return from getline: %lu\n", is_read);

	if (is_read == EOF)
	{
		printf("inside if EOF statement: %s\n", line);
		free(line);
		return (NULL);
	}
	printf("Returned line from stdin from getline: %s\n", line);
	return (line);
}
