#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * print_list - a function that prints all the elements of a list_t list
 * @h: input parameter of a pointer to a list
 * Return: the number of nodes in the list
 */
size_t print_list(const list_t *h)
{
	size_t count;

	count = 0;
	while (h != NULL)
	{
		if (h->str == NULL)
		{
			printf("[0] (nil)\n");
		}
		else
		{
			printf("[%ld] %s\n", count, h->str);
		}
		h = h->next;
		count = count + 1;
	}
	return (count);
}
