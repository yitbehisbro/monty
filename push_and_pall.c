#include "monty.h"

unsigned int status;
/**
 * _pall - prints a list of stacks
 * @list: pointer to a stack_t lists
 * @count: number of line number
 *
 * Return: no return
 */
void _pall(stack_t **list, unsigned int count)
{
	stack_t *node, *head;
	(void) count;

	if (!list || !(*list))
		return;
	node = head = *list;

	while (node)
	{
		fprintf(stdout, "%d\n", node->n);
		node = node->next;
	}
}

/**
 * _push - adds a node to a list of stacks
 * @list: pointer to a stack_t lists
 * @count: number of line number
 *
 * Return: no return
 */
void _push(stack_t **list, unsigned int count)
{
	stack_t *node = NULL;
	(void) count;

	node = malloc(sizeof(stack_t));
	if (!node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(list);
		exit(EXIT_FAILURE);
	}

	node->prev = node->next = NULL;

	if (!(*list))
		(*list) = node;
	else
	{
		(*list)->prev = node;
		node->next = *list;
		*list = node;
	}
}
