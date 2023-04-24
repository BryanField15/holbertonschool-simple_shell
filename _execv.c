#include "main.h"

/**
 * _execve - execute a program
 * @user_input: parameter of user input
 * Return: 0 on success
 */
int _execve(char *user_input)
{
	char *argv[2];

	char *input_copy;

	input_copy = strdup(user_input);
	if (input_copy == NULL)
	{
		perror("strdup");
		return (-1);
	}

	argv[0] = user_input;
	argv[1] = NULL;

	if (execve(argv[0], argv, NULL) == -1)
	{
		perror("./shell");
		return (-1);
	}
	return (0);
}
