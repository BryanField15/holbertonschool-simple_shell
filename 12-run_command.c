#include "main.h"

/**
 * run_command - executes a command in a child process
 * @input: user input from command line
 * Return: 0
 */

int run_command(char **token_array)
{
	pid_t child;
	int status;
	char *path;
	int i;

	i = 0;
	while (token_array[i] != NULL)
	{
		printf("token_array[%d]: %s\n", i, token_array[i]);
		i = i + 1;
	}
	if (token_array[0] == NULL)
	{
		return (0);
	}

	path = get_path(token_array[0]);
	printf("the path from get_path is: %s\n", path);
	if (path == NULL)
	{
		fprintf(stderr, "%s: command not found\n", token_array[0]);
		/*free(path);*/
		return (1);
	}

	child = fork();
	if (child == -1)
	{
		free(path);
		/*free(token_array);*/
		return (1);
	}
	else if (child == 0)
	{

		if (execve(path, token_array, environ) == -1)
		{
			perror("execve");
			/*free(path);*/
			exit(EXIT_FAILURE);
		}
		return (0);
	}
	else
	{
		if (wait(&status) == -1)
		{
			perror("wait");
			/*free(path);
			return (1);*/
		}
		free(path);
	}
	/*free(token_array);*/
	return (0);
}
