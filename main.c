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

	if (argc != 2)
	{
		printf("USAGE: %s file_name.m\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	input = fopen(argv[1], "r");
	if (!input)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	buffer = malloc(BUFFER_SIZE);
	if (!buffer)
	{
		fprintf(stderr, "Error: Failed to allocate memory for buffer\n");
		exit(EXIT_FAILURE);
	}
	while (fread(buffer, sizeof(BUFFER_SIZE), BUFFER_SIZE,  input))
	{
		printf("%s\n", buffer);
	}
	free(buffer);
	fclose(input);
	return (0);
}
