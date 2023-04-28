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
	printf("after getline LINE= the address %p\n", line);
	if (is_read == EOF)
	{
		printf("if EOF LINE= the address %p\n", line);
		free(line);
		return (NULL);
	}

	return (line);
}
