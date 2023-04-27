# include "main.h"
/**
 * check_builtin_cmd - find matching builtin and execute 
 *
 * Return: 0 on success and 1 if no matching builtin found
 */
int check_builtin_cmd(char **token_array)
{
	int i;

	func_t builtins_cmd[] = {
		{"env", print_env},
		{"exit", leave_shell},
		{NULL, NULL}
	};

/*	if (token_array == NULL)
	{
		return (-1);
	}
	*/
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


