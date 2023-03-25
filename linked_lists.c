#include "monty.h"
/**
 *add_dnodeint_end - adding a node at the beginning of a  lists
 *@n: the data to be added
 *@head: the node to start with
 *Return: the new node
 **/
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *temp;

	temp = malloc(sizeof(stack_t));
	if (!temp)
	{
		fprintf(stderr, "memory not allocated when adding node\n");
		exit(EXIT_FAILURE);
	}
	temp->n = n;
	temp->prev = NULL;
	temp->next = *head;
	if (*head)
		(*head)->prev = temp;
	*head = temp;
	return (temp);
}
