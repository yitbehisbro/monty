#include "monty.h"

/**
 * _stack - prints a list in LIFO
 * @list: pointer to a stack_t lists
 * @count: number of line number
 *
 * Return: no return
 */
void _stack(stack_t **list, unsigned int count)
{
	stack_t *node, *head;
	(void) count;

	if (!list || !(*list))
		return;
	node = head = *list;

	while (node)
	{
		node = node->next;
	}
}

/**
 * _queue - sets the format of the data to a queue (FIFO).
 * @head: pointer to struct
 * @count: number of line number
 *
 * Return: no return
 *
 */
void _queue(stack_t **head, unsigned int count)
{
	listint_t *prev, *next;

	if (head == NULL || *head == NULL)
		return (NULL);

	if ((*head)->next == NULL)
		return (*head);

	prev = NULL;
	while (*head != NULL)
	{
		next = (*head)->next;
		(*head)->next = prev;
		prev = *head;
		*head = next;
	}
	*head = prev;
}
