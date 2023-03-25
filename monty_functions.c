#include "monty.h"
/**
 *readfile - function that reads a file
 *@stack: a node to be added
 *@argv: array of strings
**/
void readfile(stack_t **stack, char *argv)
{
	FILE *input;
	char *buffer;
	char *line;
	unsigned int line_number;
	instruction_op call_func;

	input = fopen(argv, "r");
	if (!input)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv);
		exit(EXIT_FAILURE);
	}
	buffer = malloc(BUFFER_SIZE);
	if (!buffer)
	{
		fprintf(stderr, "Error: memory not allocated!");
		exit(EXIT_FAILURE);
	}
	line = NULL;
	line_number = 0;
	while (fgets(buffer, BUFFER_SIZE, input))
	{
		line_number++;
		line = parseline(buffer);
		if (line == NULL || line[0] == '#')
			continue;
		call_func = get_op_func(line);
		if (call_func == NULL)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, line);
			fclose(input);
			free(line);
			exit(EXIT_FAILURE);
		}
		call_func(stack, line_number);
	}
	free(buffer);
	fclose(input);
}
/**
 *get-op_func - functions maps token to all operations
 *@token: token to be mapped
 *Return: the operation functions
**/
instruction_op  get_op_func(char *token)
{
	instruction_t operations[] = {
		{"push", op_push},
		{"pall", op_pall},
		{NULL, NULL}
	};
	int i;

	i = 0;
	/* interating through the whole operations*/
	while (operations[i].opcode)
	{
		if (strcmp(operations[i].opcode, token) == 0)
			return (operations[i].f);
		i++;
	}
	return (NULL);
}
/**
 *parseline - function parse through a string
 *@line: the array of string to parse
 *Return: each token parsed
**/
char *parseline(char *line)
{
	char *token;
	char delim[] = "\n ";

	token = NULL;
	if (!line)
	{
		printf("Error: line is empty");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, delim);
	if (!token)
	{
		printf("Error: token is empty");
		exit(EXIT_FAILURE);
	}
	return (token);
}
