#include "monty.h"

/**
 * strtok_opcode - breaks down the given opcode
 * @str: string to tokenize
 *
 * Return: an array
 */
char **strtok_opcode(char *str)
{
	char *token = NULL;
	char **store;
	int i = 3;
	char *delim = "\t  \r\n";

	token = strtok(str, delim);

	if (token == NULL)
		return (NULL);

	store = malloc(sizeof(char **) * 3);
	if (store == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		free(str);
		exit(EXIT_FAILURE);
	}

	while (--i)
		store[i - 1] = NULL;

	while (token)
	{
		if (i < 3)
			store[i] = token;
		token = strtok(NULL, delim); /* pt to next token */
		i++;
	}

	store[2] = NULL;

	return (store);
}
