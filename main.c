#include "monty.h"
/**
 * main - entry point
 * @argc: argument count of the array
 * @argv: array
 * Return: (0) if successful
**/
int main(int argc, char *argv[])
{
	stack_t *stack;

	stack = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: %s file_name.m\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	readfile(&stack, argv[1]);
	return (0);
}
