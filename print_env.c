#include "main.h"

/**
 *print_env - prints the name and value current environment
 *@env: environment to print
 *Return: 0
 */

int print_env(char **env)
{
	while (*env != NULL)
	{
		printf("%s\n", *env);
		env = env + 1;
	}
	return (0);
}
