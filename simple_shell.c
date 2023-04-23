#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
/**
 * _execve - execute a program
 *
 * Return: 0 on success
 */
int _execve(char *user_input)
{
	char *argv[] = {user_input, NULL};

    if (execve(argv[0], argv, NULL) == -1)
    {
        perror("./test");
	return (-1);
    }
    return (0);
}
/**
 * read_line - read user input line
 *
 * Return: 0 on success -1 on failure
 */
char *read_line ()
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
 *
 * Return: 0
 */
int main ()
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
		input = strtok(input, "\n");

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
