#include "main.h"
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
	int return_from_builtin;

	while (1)
	{
		init_shell();
		input = read_line();
	//	printf("after read_line, the address of input is: %p (input, shell)\n", input);
		if (input == NULL)
		{
			return (0);
		}
		trimmed = trim_line(input);
	//	printf("after trim_line, the trimmed is %s\n", trimmed);
		token_array = make_token(trimmed, " ");
		return_from_builtin = check_builtin_cmd(token_array);
		if (return_from_builtin == 1)
		{
			run_command(token_array);
		}
		free_array(token_array);
		free(input);
		free(trimmed);
		fflush(stdin);
		if(return_from_builtin == 42)
		{
			break;
		}
	}
	return (0);
}
