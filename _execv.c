#include "main.h"
/**
 * _execve - execute a user command
 * @token_array: tokenised array from user input
 * Return: 0 on success, -1 on failure
 */
int _execve(char **token_array)
{
	extern char **environ;

	if (execve(token_array[0], token_array, environ) == -1)
	{
		/*perror("./shell");
		 */
		return (-1);
	}
	return (0);
}
