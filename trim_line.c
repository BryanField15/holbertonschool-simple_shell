#include "main.h"

char *trim_line(char *line)
{
	char *token;
	char *trimmed_line;
	char *result;

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
	/*free(line);
	 */

	return (result);
}
