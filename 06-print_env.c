#include "main.h"
/**
 * print_env - prints the name and value current environment
 * @token_array: unused parameter
 * Return: 0
 */

int print_env(__attribute__((unused)) char **token_array)
{
	int i;

	i = 0;
	printf("address of token passed to print env is %p (*token_array)\n", *token_array);
	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i = i + 1;
	}
	return (0);
}
