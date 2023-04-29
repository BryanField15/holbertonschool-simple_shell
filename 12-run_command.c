#include "main.h"

/**
 * run_command - executes a command in a child process
 * @token_array: array of acommandsfrom command line
 * Return: 0
 */

int run_command(char **token_array)
{
	pid_t child;
	int status, i;
	char *path;

	i = 0;
	while (token_array[i] != NULL)
	{
		i = i + 1;
	}
	if (token_array[0] == NULL)
		return (0);
	path = get_path(token_array[0]);
	if (path == NULL)
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", token_array[0]);
		return (1);
	}
	child = fork();
	if (child == -1)
	{
		free(path);
		return (1);
	}
	else if (child == 0)
	{
		if (execve(path, token_array, environ) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
		return (0);
	}
	else
	{
		if (wait(&status) == -1)
			perror("wait");
		free(path);
	}
	return (0);
}
