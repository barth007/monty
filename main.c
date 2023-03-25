#include "monty.h"
/**
 * main - entry point, reading of file
 * @argc: argument count of the array
 * @argv: array
 * Return: (0) if successful
**/
int main(int argc, char *argv[])
{
	FILE *input;
	char *buffer;
	char *line;
	unsigned int line_number;
	instruction_op call_func;
	stack_t *stack;

	stack = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: %s file_name.m\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	input = fopen(argv[1], "r");
	if (!input)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
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
		call_func(&stack, line_number);
	}
	free(buffer);
	fclose(input);
	return (0);
}
