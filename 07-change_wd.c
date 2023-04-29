#include "main.h"

/**
 *count_array_size - counts number of tokens
 *@token_array: array of user commands
 *Return: count, the number of tokens
 */

int count_array_size(char **token_array)
{
	int count;
printf("address passed to count array size is %p (*token_array)\n", *token_array);
	count = 0;
	while (token_array[count] != NULL)
	{
		count = count + 1;
	}
	return (count);
}

/**
 * change_wd - a builtint function that changes the working dir
 * @token_arrray: array of user commands
 * Return: 0 on success
 */

int change_wd(char **token_array)
{
	int result;
	int array_size;
	const char *path;
printf("address passed to change wd  is %p (*token_array)\n", *token_array);
	array_size = count_array_size(token_array);
	if (array_size > 2)
	{
		perror("cd");
		return (1);
	}
	if (array_size == 1)
	{
		chdir(getenv("HOME"));
		return (1);
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
