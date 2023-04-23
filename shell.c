#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
/**
 * _execve - execute a program
 * @user_input: parameter of user input
 * Return: 0 on success
 */
int _execve(char *user_input)
{
	char *argv[2];

	argv[0] = user_input;
	argv[1] = NULL;

	if (execve(argv[0], argv, NULL) == -1)
	{
		perror("./shell");
		return (-1);
	}
	return (0);
}

/**
 * read_line - read user input line
 * Return: pointer to the input line
 */

char *read_line()
{
	size_t length;
	char *line;
	int is_read;

	line = NULL;
	length = 0;
	is_read = getline(&line, &length, stdin);
	if (is_read == -1 && errno == 0)
	{
		exit(0);
	}
	else if (is_read == -1)
	{
		return (NULL);
	}
	return (line);
}

/**
 * main - prints prompt, waits for a users command to execute
 * Return: 0
 */
int main(void)
{
	char *input;
	pid_t child;
	int status;

	while (1)
	{
		printf("#cisfun$ ");
		input = read_line(stdin);
		if (input == NULL)
		{
			printf("%d\n", errno);
			continue;
		}
		if (input[strlen(input) - 1] == '\n')
		{
			input[strlen(input) - 1] = '\0';
		}

		child = fork();
		if (child == -1)
		{
			free(input);
			return (1);
		}
		if (child == 0)
		{
			if (_execve(input) == -1)
			{
				free(input);
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
		free(input);
	}
	return (0);
}
