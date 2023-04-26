#include "main.h"

/**
* make_token - takes the trimed line and returns an array of tokens
* @trimmed: trimmed line to be tokenised
* @delim: delimiter to separate token
* Return: pointer to token array
*/

char **make_token(char *trimmed, char *delim)
{
	int i, j;
	char *token_str;
	char *token;
	char **token_array;

	i = 0;
	j = 0;
	token_str = strdup(trimmed);
	printf("trimmed string duplicated: %s\n", token_str);
	if (token_str == NULL)
	{
		printf("the string passed to make_token is NULL\n");
		return (NULL);
	}

	token = strtok(token_str, delim);
	printf("first token is: %s\n", token);
	while (token != NULL)
	{
		i = i + 1;
		token = strtok(NULL, delim);
	}

	token_array = malloc(sizeof(*token_array) * (i + 1));
	if (token_array == NULL)
	{
		printf("token_array is null");
		free(token_str);
		return (NULL);
	}
	i = 0;
	token = strtok(trimmed, delim);
	while (token != NULL)
	{
		token_array[i] = strdup(token);
		i = i + 1;
		token = strtok(NULL, delim);
	}
	token_array[i] = NULL;
	while (token_array[j] != NULL)
	{
		printf("token array is :%s\n", token_array[j]);
		j = j + 1;
	}
	/*printf("free token str");
	free(token_str);
	 */
	return (token_array);
}
