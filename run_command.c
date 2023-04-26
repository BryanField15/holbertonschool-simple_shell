#include "main.h"

/**
 *run_command - executes a command in a child process
 *@input: user input from command line
 *Return: 0
 */

int run_command(char **token_array)
{
	pid_t child;
	int status;
	char *path;

	path = NULL;

	if (token_array[0] == NULL)
	{
		return (0);
	}

	path = get_path(token_array[0]);
	if (path == NULL)
	{
		fprintf(stderr, "%s: command not found\n", token_array[0]);
		return (1);
	}
	child = fork();
	if (child == -1)
	{
		free(token_array);
		return (1);
	}
	else if (child == 0)
	{
		if (_execve(token_array) == -1)
		{
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
	return (0);
}
