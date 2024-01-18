#include "monty.h"

/**
 * pall - A function that prints all the elements of the stack
 * @stack: The stack to print
 * @line_number: The Line number
 *
 * Return: Nothing
 * This program conforms to the betty documentation style
 **/

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void) line_number;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
