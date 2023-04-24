#include "main.h"

/**
 * main - prints prompt, waits for a users command to execute
 * Return: 0
 */

int main(void)
{
	char *input;

	while (1)
	{
		init_shell();
		input = read_line(stdin);
		if (input == NULL)
		{
			free(input);
			break;
		}

		if (input[strlen(input) - 1] == '\n')
		{
			input[strlen(input) - 1] = '\0';
		}
		run_command(input);
		free(input);
	}
	return (0);
}
