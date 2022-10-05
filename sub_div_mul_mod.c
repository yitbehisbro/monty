#include "monty.h"

/**
 * _sub - subtracts the top element of the stack
 * @stack: pointer to a stack_t list
 * @line_number: line count
 *
 * Return: void has no return
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || (*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		if (*stack)
			free_stack(stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = ((*stack)->next->n) - ((*stack)->n);
	_pop(stack, line_number);
}

/**
 * _div - divides the second top element of the stack
 * @stack: pointer to a stack_t
 * @line_number: line count
 *
 * Return: void has no return
 */
void _div(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || (*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		if (*stack)
			free_stack(stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = ((*stack)->next->n) / ((*stack)->n);
	_pop(stack, line_number);
}

/**
 * _mul - multiplies the second top element of the stack
 * @stack: pointer to stack_t
 * @line_number: line count
 *
 * Return: void has no return
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || (*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		if (*stack)
			free_stack(stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = ((*stack)->next->n) * ((*stack)->n);
	_pop(stack, line_number);
}

/**
 * _mod - computes the rest of the division of the second top element
 * of the stack by the top element of the stack
 * @stack: pointer to a stack_t
 * @line_number: line count
 *
 * Return: void has no return
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || (*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		if (*stack)
			free_stack(stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = ((*stack)->next->n) % ((*stack)->n);
	_pop(stack, line_number);
}
