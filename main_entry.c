#define _GNU_SOURCE
#include <stdio.h>
#include "monty.h"

unsigned int count_line = 0;

/**
 * start_flags - initializes the global variables
 *
 * @fd: file descriptor
 * Return: no return
 */
void start_flags(FILE *fd)
{
	flags.status = 1;
	flags.cont = 1;
	flags.arg = NULL;
	flags.head = NULL;
	flags.fd = fd;
	flags.buffer = NULL;
}

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
	start_flags(fd);
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
