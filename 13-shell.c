#include "main.h"
/**
 * main - a simple UNIX command interpreter
 * Return: 0
 */

int main(void)
{
	char *input;
	char *trimmed;
	char **token_array;

	while (1)
	{
		init_shell();
		input = read_line();
		printf("after read_line, the address of input is: %p\n (input, shell)", input);
		if (input == NULL)
		{
			return (0);
		}
		trimmed = trim_line(input);
		token_array = make_token(trimmed, " ");
		if (check_builtin_cmd(token_array) == 1)
		{
			run_command(token_array);
		}
		free(token_array);
		printf("after run_command, the address of input is: %p\n(input, shell", input);
		free(input);
		fflush(stdin);
	}
	return (0);
}
