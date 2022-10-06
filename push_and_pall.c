#include "monty.h"

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
	int n, j;

	if (!flags.arg)
	{
		fprintf(stderr, "L%u: usage: push integer\n", count);
		free_stack(list);
		exit(EXIT_FAILURE);
	}

	for (j = 0; flags.arg[j] != '\0'; j++)
	{
		if (!isdigit(flags.arg[j]) && flags.arg[j] != '-')
		{
			fprintf(stderr, "L%u: usage: push integer\n", count);
			free_stack(list);
			exit(EXIT_FAILURE);
		}
	}

	n = atoi(flags.arg);

	if (flags.status == 1)
		add_dnodeint(list, n);
	else
		add_dnodeint_end(list, n);
}
