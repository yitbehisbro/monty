#include "monty.h"

/**
 * _pchar - prints the char at the top of the stack, followed by a new line.
 * @stack: pointered to a stack_t lists
 * @n: line counts
 *
 * Return: void has no return
 */
void _pchar(stack_t **stack, unsigned int n)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", n);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", n);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	fprintf(stdout, "%c\n", (*stack)->n);
}


/**
 * _pstr - prints the string starting at the top of the stack
 * @stack: pointered to a stack_t lists
 * @n: line counts
 *
 * Return: void has no return
 */
void _pstr(stack_t **stack, unsigned int n)
{
	stack_t *node;
	(void) n;

	if (!stack || !(*stack))
	{
		fprintf(stdout, "\n");
		return;
	}

	node = *stack;
	while (node)
	{
		if (node->n <= 0 || node->n > 127)
			break;
		fprintf(stdout, "%c", node->n);
		node = node->next;
	}
	fprintf(stdout, "\n");
}
