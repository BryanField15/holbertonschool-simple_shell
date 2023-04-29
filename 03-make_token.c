#include "main.h"

/**
 * list_to_array - converts a linked list to an array
 * @head: pointer to head of list
 * Return: array
 */

char **list_to_array(list_t *head)
{
	size_t length;
	char **array;
	size_t index;

	length = list_len(head);
	array = malloc(sizeof(*array) * (length + 1));

	index = 0;
	while (head != NULL)
	{
		array[index] = strdup(head->str);
		index = index + 1;
		head = head->next;
	}
	array[index] = NULL;
	return (array);
}

/**
* make_token - takes the trimed line and returns an array of tokens
* @trimmed: trimmed line to be tokenised
* @delim: delimiter to separate token
* Return: pointer to token array
*/

char **make_token(char *trimmed, char *delim)
{
	char *token_str;
	char *token;
	char **token_array;
	list_t *head;

	head = NULL;
	token_str = strdup(trimmed);

	if (token_str == NULL)
	{
		return (NULL);
	}

	token = strtok(token_str, delim);
	while (token != NULL)
	{
		add_node_end(&head, token);
		token = strtok(NULL, delim);
	}
	token_array = list_to_array(head);
	free_list(head);
	free(token_str);
	return (token_array);
}
