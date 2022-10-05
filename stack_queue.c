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
	(void) count;

	reverse(head);
}

/**
 * reverse - reverses the stacks
 * @head: pointer to struct
 * @count: number of line number
 *
 * Return: no return
 *
 */
void reverse(stack_t **head)
{
	stack_t *temp = NULL;
	stack_t *current = *head;

	while (current !=  NULL)
	{
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		current = current->prev;
	}
	if (temp != NULL)
		*head = temp->prev;
}
