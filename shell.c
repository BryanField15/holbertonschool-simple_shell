#include "main.h"

/**
 * main - prints prompt, waits for a users command to execute
 * Return: 0
 */

int main(void)
{
	char *input;
	pid_t child;
	int status;

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
		child = fork();
		if (child == -1)
		{
			free(input);
			return (1);
		}
		if (child == 0)
		{
			if (_execve(input) == -1)
			{
				free(input);
				return (1);
			}
			return (0);
		}
		else
		{
			if (wait(&status) == -1)
			{
				perror("wait");
			}
		}
		free(input);
	}
	return (0);
}
