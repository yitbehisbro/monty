#include "monty.h"

/**
 * free_stack - frees up the memory block of the stack
 * @stack: pointer to stack_t list
 *
 * Return: void has no return
 */
void free_stack(stack_t **stack)
{
	stack_t *head = *stack;

	while (head)
	{
		if (!head->next)
		{
			free(head);
			break;
		}
		head = head->next;
		free(head->prev);
	}
}
