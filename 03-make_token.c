#include "main.h"

/**
* make_token - takes the trimed line and returns an array of tokens
* @trimmed: trimmed line to be tokenised
* @delim: delimiter to separate token
* Return: pointer to token array
*/

char **make_token(char *trimmed, char *delim)
{
	int i;
	char *token_str;
	char *token;
	char **token_array;

	i = 0;
	token_str = strdup(trimmed);

	if (token_str == NULL)
	{
		return (NULL);
	}
	printf("Allocated memory after trimmed dupped: %p (token_str)\n", token_str);
	token = strtok(token_str, delim);
	while (token != NULL)
	{
		i = i + 1;
		token = strtok(NULL, delim);
	}

	token_array = malloc(sizeof(*token_array) * (i + 1));
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