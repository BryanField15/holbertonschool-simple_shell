#include "main.h"

/**
 * free_array - frees an array
 * @array: array to be freed
 * Return: void
 */
void free_array(char **array)
{
	size_t index;

	index = 0;
	while (array[index] != NULL)
	{
		free(array[index]);
		index = index + 1;
	}
	free(array);
}

/**
 * main - a simple UNIX command interpreter
 * Return: 0
 */

int main(void)
{
	char *input;
	char *trimmed;
	char **token_array;
	int ret_from_builtin;

	while (1)
	{
		init_shell();
		input = read_line();

		if (input == NULL)
		{
			return (0);
		}
		trimmed = trim_line(input);
		token_array = make_token(trimmed, " ");
		ret_from_builtin = check_builtin_cmd(token_array);
		if (ret_from_builtin == 1)
		{
			run_command(token_array);
		}
		free_array(token_array);
		free(input);
		free(trimmed);
		fflush(stdin);
		if (ret_from_builtin == 42)
		{
			break;
		}
	}
	return (0);
}
