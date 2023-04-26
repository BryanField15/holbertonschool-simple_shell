#include "main.h"
/**
 * _execve - execute a user command
 * @token_array: tokenised array from user input
 * Return: 0 on success, -1 on failure
 */



int _execve(char **token_array)
{
	extern char **environ;

	if (token_array == NULL || token_array[0] == NULL)
	{
		return (-1);
	}

	if (execve(token_array[0], token_array, environ) == -1)
	{
		return (-1);
	}

	free(token_array);
	return (0);
}
