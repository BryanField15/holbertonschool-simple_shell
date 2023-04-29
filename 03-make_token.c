#include "main.h"
char **list_to_array(list_t *head)
{
	size_t length;
	char **array;
	size_t index;

	length = list_len(head);
	array = malloc(sizeof(*array) * (length + 1));
	/*check malloc
	 * */
	index = 0;
	while (head != NULL)
	{
		array[index] = strdup(head->str);
		index = index + 1;
		head = head->next;
	}
	array[index] == NULL;
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
//	printf("Allocated memory after trimmed dupped: %p (token_str)\n", token_str);
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

/*	token_array = malloc(sizeof(*token_array) * (i + 1));
	if (token_array == NULL)
	{
		printf("Freeing memory if malloc fails: %p (token_str)\n", token_str);
		free(token_str);
		return (NULL);
	}
	i = 0;
	token = strtok(trimmed, delim);
	while (token != NULL)
	{
		token_array[i] = token;
		token = strtok(NULL, delim);
		i = i + 1;
	}
	token_array[i] = NULL;
	printf("Freeing memory after making token: %p (token_str)\n", token_str);
	free(token_str);
	return (token_array);
}
*/
