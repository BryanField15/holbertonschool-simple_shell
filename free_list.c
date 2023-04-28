#include "main.h"
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

