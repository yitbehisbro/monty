#include "monty.h"

/**
 * _rotl - rotates the stack to the top.
 * @stack: pointer to a stack_t lists
 * @n: line count
 *
 * Return: void has no return
 */
void _rotl(stack_t **stack, unsigned int n)
{
	stack_t *h = NULL, *t = NULL;
	(void) n;

	if (!stack || !(*stack) || !(*stack)->next)
		return;

	h = *stack;
	t = h->next;
	t->prev = NULL;
	*stack = t;
	while (t->next)
	{
		t = t->next;
	}
	t->next = h;
	h->prev = t;
	h->next = NULL;
}

/**
 * _rotr - rotates the stack to the bottom.
 * @stack: pointer to a stack_t lists
 * @n: line count
 *
 * Return: void has no return
 */
void _rotr(stack_t **stack, unsigned int n)
{
	stack_t *h = NULL, *t = NULL;
	(void) n;

	if (!stack || !(*stack) || !(*stack)->next)
		return;

	t = h = *stack;
	while (h->next)
		h = h->next;

	h->prev->next = NULL;
	h->next = t;
	h->prev = NULL;
	t->prev = h;
	*stack = h;
}
