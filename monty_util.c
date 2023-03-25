#include "monty.h"
/**
 * _isdigit -  a function that checks if a string contain a string
 * @str: input
 * Return: 1 if str contains a digit, 0 otherwise
 */
int _isdigit(char *str)
{
	if (!str || !*str)
		return (1);
	if (*str == '_')
		return (1);
	while (*str)
	{
		if (!isdigit(*str))
			return (1);
		str++;
	}
	return (0);
}
