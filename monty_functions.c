#include "monty.h"

/**
 *parseline - function parse through a string
 *@line: the array of string to parse
 *Return: each token parsed
**/
char *parseline(char *line)
{
	char *token;

	token = NULL;
	if (!line)
	{
		printf("Error: line is empty");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, "\n");
	if (!token)
	{
		printf("Error: token is empty");
		exit(EXIT_FAILURE);
	}
	printf("%s\n", token);
	return (token);
}
