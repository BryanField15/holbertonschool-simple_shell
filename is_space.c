#include "main.h"
/**
 * is_space - check if the input string contains only spaces
 * @str: input string
 * Return: 0 if contains only spaces
 */
int is_space(char *str)
{
	int check;
	int count;

	count = 0;
	while (str[count] != '\0')
	{
		check = isspace(str[count]);
		if (check != 0)
		{
			count = count + 1;
		}
		else
			return (1);
	}
	return (0);
}
