#include "main.h"
/**
 * count_array_size - counts number of tokens
 * @token_array: array of user commands
 * Return: count, the number of tokens
 */

int count_array_size(char **token_array)
{
	int count;

	count = 0;
	while (token_array[count] != NULL)
	{
		count = count + 1;
	}
	return (count);
}

/**
 * change_wd - a builtint function that changes the working dir
 * @token_array: array of user commands
 * Return: 0 on success
 */

int change_wd(char **token_array)
{
	int result;
	int array_size;
	const char *path;

	array_size = count_array_size(token_array);
	if (array_size > 2)
	{
		perror("cd");
		return (1);
	}
	if (array_size == 1)
	{
		chdir(_getenv("HOME"));
		return (0);
	}

	path = token_array[1];
	result = chdir(path);
	if (result != 0)
	{
		perror("cd");
		return (1);
	}
	return (0);
}
