#include "main.h"
/**
 * trim_line - get rid off the leading and trailing spaces
 * @line: pointer to line to be trimmed
 * Return: pointer to the trimmed line
 */

char *trim_line(char *line)
{
	char *end;

	while (isspace(*line) != 0)
	{
		line = line + 1;
	}

	if (*line == '\0')
	{
		return (line);
	}

	end = line + strlen(line) - 1;
	while (end > line && (isspace(*end) != 0))
	{
		end = end - 1;
	}

	end[1] = '\0';
	return (line);
}
