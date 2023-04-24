#include "main.h"

/**
 * read_line - read user input line
 * Return: pointer to the input line
 */

char *read_line()
{
	size_t length;
	char *line, *token, *trimmed_line, *result;
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

	token = strtok(line, " \t\n");
	if (token != NULL)
	{
		trimmed_line = token;
		while ((token = strtok(NULL, " \t\n")) != NULL)
		{
			trimmed_line = token;
		}
	} else
	{
		trimmed_line = line;
	}

	result = strdup(trimmed_line);
	free(line);

	return (result);
}
