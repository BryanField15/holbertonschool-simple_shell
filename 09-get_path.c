#include "main.h"

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
