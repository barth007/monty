#include "monty.h"
void op_push(stack_t **stack, unsigned int line)
{
	char *arg_str;
	int data;

	data = 0;
	arg_str = strtok(NULL, "\n\t");
	if (_isdigit(arg_str) == 0)
		data = atoi(arg_str);
	else
	{
		fprintf(stderr, "L%u: unkown instruction %s\n", line, arg_str);
		exit(EXIT_FAILURE);
	}
	add_dnodeint_end(stack, data);
}
void op_pall(stack_t **stack, __attribute__ ((unused))unsigned int line)
{
	stack_t *pointer;

	if (!(*stack))
		exit(EXIT_FAILURE);

	pointer = *stack;
	while (pointer != NULL)
	{
		printf("%d\n", pointer->n);
		pointer = pointer->next;
	}
}
