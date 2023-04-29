#include "main.h"

/**
 * _getenv - a function that gets an environment variable
 * @name: pointer to the name of the env variable to be fetched
 * Return: NULL if not found; pointer to the corresponding value string
 */

/*char *_getenv(const char *name)
{
        char **environ_ptr;
        char *str;
        int i;

        i = 0;
        environ_ptr = environ;
        printf("environ_ptr memory after init: %p\n", (void *)environ_ptr);
        if (environ_ptr == NULL)
        {
                return (NULL);
        }
        while (environ_ptr[i] != NULL)
        {
                char *env_copy = strdup(environ_ptr[i]);
                str = strtok(env_copy, "=");
		printf("str after strdup: %p\n", str);
                if (strcmp(str,  name) == 0)
                {
                        str = strtok(NULL, "=");
                        printf("str after second strtok: %p\n", str);
                        free(env_copy);
                        return (str);
                }
                free(env_copy);
                i = i + 1;
        }
        return (NULL);
	}*/
char *_getenv(const char *name)
{
	char **environ_ptr;
	char *str;
	int i;

	i = 0;
	environ_ptr = environ;
	printf("environ_ptr memory after init: %p\n", (void *)environ_ptr);
	if (environ_ptr == NULL)
	{
		return (NULL);
	}
	while (environ_ptr[i] != NULL)
	{
		str = strtok(strdup(environ_ptr[i]), "=");
		printf("str after strdup: %p\n", str);
		if (strcmp(str,  name) == 0)
		{
			str = strtok(NULL, "=");
			printf("str after second strtok: %p\n", str);
			return (str);
		}
		i = i + 1;
	}
	return (NULL);
}

/**
 * add_node_end - a function that adds a new node at the end
 * of a list_t list
 * @head: input parameter of a pointer to the beginning of a linked list
 * @str: input string that too be added at the end
 * Return: the address of the new element or NULL if it faild
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *temp = malloc(sizeof(list_t));
	list_t *ptr;
	unsigned int i;

	if (temp == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (str[i] != '\0')
	{
		i = i + 1;
	}
	temp->str = strdup(str);
	temp->len = i;
	temp->next = NULL;
	if (*head == NULL)
	{
		*head = temp;
	}
	else
	{
		ptr = *head;
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = temp;
	}
	return (temp);
}

/**
 * _path_to_list - a function that builds a linked list of the PATH directories
 * @command: command to be checked
 * Return: pointer to the list
 */

list_t *_path_to_list(char *command)
{
	char *str;
	list_t *node;
	char *dir;
	char *full_path;

	str = getenv("PATH");
	dir = strtok(str, ":");
	node = NULL;
	while (dir != NULL)
	{
		full_path = malloc(sizeof(*full_path) * (strlen(command) + strlen(dir) + 2));
		full_path[0] = '\0';
		strcat(full_path, dir);
		strcat(full_path, "/");
		strcat(full_path, command);
		add_node_end(&node, full_path);
		dir = strtok(NULL, ":");
		/*free(full_path);*/
	}
	free(full_path);
	/*free(str);*/
	return (node);
}
