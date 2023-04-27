# include "main.h"
/**
 * check_builtin_cmd - check if 
 *
 * Return: 0
 */
int check_builtin_cmd(char **token_array)
{
	func_t builtins_cmd[] = {
		{"env", print_env},
		{"exit", leave_shell},
		{NULL, NULL}
	};
	int i;

	i = 0;
	while (builtins_cmd[i].name != NULL)
	{
		if (strcmp(builtins_cmd[i].name, token_array[0]) == 0)
		{
			builtins_cmd[i].f(token_array);
			return (0);
		}
		i = i + 1;
	}
	return (1);
}


