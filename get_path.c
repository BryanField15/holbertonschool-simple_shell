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
		str = strtok(strdup(environ[i]), "=");
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
 * add_node - a function that adds a new node at the beginning
 * of a list_t list
 * @head: input parameter of a pointer to the beginning of a linked list
 * @str: input string that too be added at the beginning
 * Return: the address of the new element or NULL if it faild
 */

list_t *add_node(list_t **head, const char *str)
{
        list_t *ptr = malloc(sizeof(list_t));
        unsigned int i;

        if (ptr == NULL)
        {
                return (NULL);
        }
        i = 0;
        while (str[i] != '\0')
        {
                i = i + 1;
        }
        ptr->str = strdup(str);
        ptr->len = i;
        ptr->next = NULL;

        ptr->next = *head;
        *head = ptr;
        return (*head);
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

list_t * _path_to_list(char *command)
{
	char *str;
	list_t *node;
	char *dir;
	char *full_path;

	str = _getenv("PATH");
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
		free(full_path);
	}
	return (node);
}

/**
 * free_list - frees a linked list
 * @head: head of linked list
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
 *@command: user command
 *Return: path required to execute
 */

char *get_path(char *command)
{
	list_t *head;
	list_t *tmp;
	char *path;
	struct stat st;

	head = _path_to_list(command);
	add_node(&head, command);
	tmp = head;
	while (tmp != NULL)
	{
		if (stat(tmp->str, &st) == 0 && ((st.st_mode & S_IXUSR) == S_IXUSR))
		{
			path = strdup(tmp->str);
			free_list(head);
			return (path);
		}
		tmp = tmp->next;
	}
	free_list(head);
	return (NULL);
}
