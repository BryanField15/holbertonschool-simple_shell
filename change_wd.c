# include "main.h"
/**
 * change_wd - a builtint function that changes the working dir
 * @
 * Return: 0 on success
 */
int change_wd(char **token_array)
{
	int result;
	const char *path;
	
	if (strcmp(token_array[0], "cd") == 0 && token_array[1] == NULL)
	{
		chdir(getenv("HOME"));
	}
	else if (token_array[2] == NULL)
	{
		path = token_array[1];
		printf("we are in the builtin cd and get path\n");
		result = chdir(path);
		if (result != 0)
		{
			perror("cd");
			return (1);
		}
	}
	else
	{
		return (1);
	}
	return (0);
}
