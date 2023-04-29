# include "main.h"

/**
 *check_builtin_cmd - find matching builtin and execute
 *@token_array: array of user commands
 *Return: 0 on success and 1 if no matching builtin found
 */

int check_builtin_cmd(char **token_array)
{
	int i;

	func_t builtins_cmd[] = {
		{"env", print_env},
		{"exit", leave_shell},
		{"cd", change_wd},
		{NULL, NULL}
	};

	i = 0;

	while (builtins_cmd[i].name != NULL)
	{
		if (strcmp(builtins_cmd[i].name, token_array[0]) == 0)
		{
			return (builtins_cmd[i].f(token_array));
		}
		i = i + 1;
	}
	return (1);
}
