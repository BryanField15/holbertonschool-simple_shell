#include "main.h"

/**
 *init_shell - prints a prompt and waits for a user command
 *Return: void
 */

void init_shell()
{
	if (isatty(STDIN_FILENO) == 1)
	{
		printf("#cisfun$ ");
	}
	return;
}