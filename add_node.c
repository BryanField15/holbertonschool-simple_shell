#include "main.h"
/**
 * add_node - a function that adds a new node at the beginning
 * of a list_t list
 * @head: input parameter of a pointer to the beginning of a linked list
 * @str: input string that too be added at the beginning
 * Return: the address of the new element or NULL if it faild
 */

list_t *add_node(list_t **head, const char *str)
{
        list_t *ptr = malloc(sizeof(list_t));
        unsigned int i;

        if (ptr == NULL)
        {
                return (NULL);
        }
        i = 0;
        while (str[i] != '\0')
        {
                i = i + 1;
        }
        ptr->str = strdup(str);
        ptr->len = i;
        ptr->next = NULL;

        ptr->next = *head;
        *head = ptr;
        return (*head);
}

