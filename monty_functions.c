#include "monty.h"
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
