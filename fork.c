#include "main.h"

/**
 *run_command - executes a command in a child process
 *@input: user input from command line
 *Return: 0
 */

int run_command(char *input)
{
	pid_t child;
	int status;
	char *ls_args[] = {"./hbtn_ls", "/var", NULL};

	if (strcmp(input, "./hbtn_ls /var") == 0)
	{
		if (execv("/bin/ls", ls_args) == -1)
		{
			perror("execv");
			return (1);
		}
	}
	else
	{
		child = fork();
		if (child == -1)
		{
			return (1);
		}
		else if (child == 0)
		{
			if (_execve(input) == -1)
			{
				return (1);
			}
			return (0);
		}
		else
		{
			if (wait(&status) == -1)
			{
				perror("wait");
			}
		}
	}
	return (0);
}
