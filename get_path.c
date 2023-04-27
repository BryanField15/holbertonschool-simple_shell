#include "main.h"

/**
 * _getenv - a function that gets an environment variable
 * @name: pointer to the name of the env variable to be fetched
 * Return: NULL if not found; pointer to the corresponding value string
 */
char *_getenv(const char *name)
{
        extern char **environ;
        char *str;
        int i;

        i = 0;
        while (environ[i] != NULL)
        {
                str = strtok(environ[i], "=");
                if (strcmp(str,  name) == 0)
                {
                        str = strtok(NULL, "=");
                        return (str);
                }
                i = i + 1;
        }
        return (NULL);
}

/**
 * _path_to_list - a function that builds a linked list of the PATH directories
 *
 * Return: pointer to the list
 */

list_t * _path_to_list()
{
	char *str;
	list_t *node;
	char *dir;

	str = _getenv("PATH");
	dir = strtok(str, ":");
	node = NULL;
	while (dir != NULL)
	{
		node = add_node_end(&node, dir);
		dir = strtok(NULL, ":");
	}
	return (node);
}

/**
 * free_list - frees a linked list
 * Return: void
 */
void free_list(list_t *head)
{
	list_t *tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp->str);
		free(tmp);
	}
}

/**
 *get_path - handles the path variable and only forks if it is found
 *@command:
 *
 *Return: NULL
 */

char *get_path(char *command)
{
	
}
