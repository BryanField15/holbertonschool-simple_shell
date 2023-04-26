#include "main.h"

/**
 * main - a simple UNIX command interpreter
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
		trimmed = trim_line(input);
		token_array = make_token(trimmed, " ");
		run_command(token_array);
		free(token_array);
		free(input);
	}
	return (0);
}
