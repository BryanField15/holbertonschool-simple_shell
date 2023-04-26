#include "main.h"

/**
 * main - prints prompt, waits for a users command to execute
 * Return: 0
 */

int main(void)
{
	char *input;
	char *trimmed;
	char **token_array;

	while (1)
	{
		init_shell();
		input = read_line();
		if (input == NULL)
		{
			return (0);
		}

		/*if (input[strlen(input) - 1] == '\n')
		{
			input[strlen(input) - 1] = '\0';
		}
		*/
		trimmed = trim_line(input);
		token_array = make_token(trimmed, " ");
		run_command(token_array);
		free(token_array);
		free(trimmed);
		
		if (input != NULL)
		{
			free(input);
		}
	}
	return (0);
}
