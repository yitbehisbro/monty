#include "monty.h"
#include <stdlib.h>

/**
 * _stack - prints a list in LIFO
 * @list: pointer to a stack_t lists
 * @count: number of line number
 *
 * Return: no return
 */
void _stack(stack_t **list, unsigned int count)
{
	(void) list;
	(void) count;
	flags.status = 1;
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
	(void) head;
	(void) count;
	flags.status = 0;
}
