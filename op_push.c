#include "monty.h"

/**
 * push - A function that adds a new node at the beginning
 * of the stack function 
 * @stack: The head of the stack
 * @param: The value to add on the stack
 *
 * Return: Nothing
 * This program conforms to the betty documentation style
 **/

void push(stack_t **stack, unsigned int param)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		handle_error(ERR_BAD_MALL, NULL, 0, NULL);

	new_node->n = param;
	new_node->next = *stack;
	new_node->prev = NULL;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * push_queue - A function that adds a new node at the end of the stack
 * @stack: The head of the stack
 * @param: The value to add on the stack
 *
 * Return: Nothing
 * This program conforms to the betty documentation style
 **/

void push_queue(stack_t **stack, unsigned int param)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		handle_error(ERR_BAD_MALL, NULL, 0, NULL);

	new_node->n = param;
	new_node->next = NULL;

	if (*stack)
	{
		stack_t *current = *stack;
		while (current->next != NULL)
			current = current->next;

		new_node->prev = current;
		current->next = new_node;
	}
	else
	{
		new_node->prev = NULL;
		*stack = new_node;
	}
}
