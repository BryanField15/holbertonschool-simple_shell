#include "main.h"
/**
 *print_env - prints the name and value current environment
 *@env: environment to print
 *Return: 0
 */

int print_env(__attribute__((unused)) char **token_array)
{
	extern char **environ;	
	int count;

	count = 0;
	while (environ[count] != NULL)
	{
		printf("In print_env While() \n");
		printf("%s\n", environ[count]);
		count = count + 1;
	}
	return (0);
}
