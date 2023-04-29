#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * list_len - a function that returns the numver of elementsin
 * in a linked list_t list
 * @h: input parameter of a pointer to a list
 * Return: the number of elements in the list
 */
size_t list_len(const list_t *h)
{
	size_t count;

	count = 0;
	while (h != NULL)
	{
		h = h->next;
		count = count + 1;
	}
	return (count);
}
