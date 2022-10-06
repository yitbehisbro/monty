#ifndef _MONTY_H_
#define _MONTY_H

#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

extern unsigned int count_line;
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct queue_and_stack - structure to use in the functions
 * @lifo: is stack or queue
 * @cont: current line
 * @arg: second parameter inside the current line
 * @head: doubly linked list
 * @fd: file descriptor
 * @buffer: input text
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct queue_and_stack
{
	unsigned int cont;
	char  *arg;
	stack_t *head;
	FILE *fd;
	char *buffer;
} queue_and_stack_t;

extern queue_and_stack_t flags;

/***************push_and_pall.c************/
void _pall(stack_t **list, unsigned int count);
void _push(stack_t **list, unsigned int count);

/***************opcode.c*******************/
void call(char **opcode_tokens, stack_t **stack);
void is_token(char **opcode_tokens, stack_t **stack);

/**************strtok.c********************/
char **strtok_opcode(char *str);

/*************free_stack.c***************/
void free_stack(stack_t **stack);

/************pop_pint_swap_add.c*********/
void _pop(stack_t **stack, unsigned int number);
void _pint(stack_t **stack, unsigned int number);
void _swap(stack_t **stack, unsigned int count_line);
void _add(stack_t **stack, unsigned int count_line);

/**************sub_div_mul_mod.c*********/
void _sub(stack_t **stack, unsigned int count_line);
void _div(stack_t **stack, unsigned int count_line);
void _mul(stack_t **stack, unsigned int count_line);
void _mod(stack_t **stack, unsigned int count_line);

/**************pchar_pstr.c**************************/
void _pchar(stack_t **stack, unsigned int count_line);
void _pstr(stack_t **stack, unsigned int count_line);

/*************rotl_and_rotr.c*********************/
void _rotl(stack_t **stack, unsigned int count_line);
void _rotr(stack_t **stack, unsigned int count_line);

/*************stack_queue.c*********************/
void _stack(stack_t **stack, unsigned int count_line);
void _queue(stack_t **stack, unsigned int count_line);

/*****************doubly_linked_list.c***************/
dlistint_t *add_dnodeint(dlistint_t **head, const int n);
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n);

#endif
