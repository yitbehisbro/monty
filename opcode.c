#include "monty.h"

static instruction_t ops[] = {
	{"push", _push}, {"pall", _pall}, {"pint", _pint}, {"pop", _pop},
	{"swap", _swap}, {"add", _add}, {"nop", NULL}, {"sub", _sub}, {"div", _div},
	{"mul", _mul}, {"mod", _mod}, {"pchar", _pchar}, {"pstr", _pstr},
	{"rotl", _rotl}, {"rotr", _rotr}, {"stack", _stack}, {"queue", _queue},
	{NULL, NULL}
};

/**
 * call - call the particular function
 * @opcode_tokens: tokens of opcode
 * @stack: pointer to stack_t
 *
 * Return: void has nothing to return
 */
void call(char **opcode_tokens, stack_t **stack)
{
	int i = 0;

	while (ops[i].opcode)
	{
		if (opcode_tokens[0][0] == '#')
			return;
		if (strcmp(opcode_tokens[0], ops[i].opcode) == 0)
		{
			if (ops[i].f)
				ops[i].f(stack, count_line);
			break;
		}
		i++;
	}

	if (strcmp(opcode_tokens[0], "push") == 0)
	{
		is_token(opcode_tokens, stack);
		(*stack)->n = atoi(opcode_tokens[1]);
	}
	else if (!(ops[i].opcode))
	{
		fprintf(stderr, "L%u: unknown instruction %s\n",
			count_line,
			opcode_tokens[0]);
		exit(EXIT_FAILURE);
	}
}

/**
 * is_token - check if a token is valid
 * @opcode_tokens: opcode tokens
 * @stack: pointer to a stack_t
 *
 * Return: void has no return
 */
void is_token(char **opcode_tokens, stack_t **stack)
{
	int i = 0;

	if (!opcode_tokens[1])
	{
		fprintf(stderr, "L%u: usage: push integer\n", count_line);
		if (*stack)
			free_stack(stack);
		free(opcode_tokens);
		exit(EXIT_FAILURE);
	}

	while (opcode_tokens[1][i])
	{
		if (opcode_tokens[1][i] == '-' && i == 0)
			i++;
		if (isdigit(opcode_tokens[1][i]) == 0)
		{
			fprintf(stderr, "L%u: usage: push integer\n", count_line);
			if (*stack)
				free_stack(stack);
			free(opcode_tokens);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}
