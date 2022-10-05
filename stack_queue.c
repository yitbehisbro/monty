#include "monty.h>

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
