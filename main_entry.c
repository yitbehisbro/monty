#define _GNU_SOURCE
#include <stdio.h>
#include "monty.h"

unsigned int count_line = 0;

/**
 * main - entry point for all the program
 * @argc: number of arguments passed
 * @argv: vector of the argument
 *
 * Return: 0 in success
 */
int main(int argc, char *argv[])
{
	char **tokens = NULL;
	stack_t *head = NULL;
	char *buffer = NULL;
	FILE *fp;
	size_t n;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r+");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((getline(&buffer, &n, fp)) != -1)
	{
		count_line++;
		tokens = strtok_opcode(buffer);
		if (tokens)
		{
			call(tokens, &head);
			free(tokens);
		}
	}
	free(buffer);
	free_stack(&head);
	fclose(fp);

	return (0);
}
