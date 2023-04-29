#include "main.h"

/**
 * trim_line - get rid off the leading and trailing spaces
 * @line: pointer to line to be trimmed
 * Return: pointer to the trimmed line
 */

char *trim_line(char *line)
{
	char *start;
	char *end;
	size_t len;

	len = strlen(line);
	start = line;
	end =  &line[len - 1];
	if (len == 1)
	{
		return (strdup(""));
	}
	while (isspace(*start) != 0)
	{
		start = start + 1;
	}

	while (end > start && (isspace(*end) != 0))
	{
		end = end - 1;
	}

	end[1] = '\0';
	return (strdup(start));
}
