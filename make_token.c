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
/*	printf("trimmed string duplicated: %s\n", token_str);*/
	if (token_str == NULL)
	{
/*		printf("the string passed to make_token is NULL\n");*/
		return (NULL);
	}

	token = strtok(token_str, delim);
/*	printf("first token is: %s\n", token);*/
	while (token != NULL)
	{
		token = strtok(NULL, delim);
		i = i + 1;
	}
/*	free(token_str);*/

	token_array = malloc(sizeof(*token_array) * (i + 1));
	if (token_array == NULL)
	{
/*		printf("token_array is null");*/
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
	free(token_str);
	return (token_array);
}
