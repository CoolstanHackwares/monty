#include "monty.h"

/**
 * frees_stack - ...
 *
 * Return: ...
 * This program conforms to the betty documentation style
 **/

void frees_stack(void)
{
	stack_t *temp = NULL;

	if (head)
	{
		temp = head;
		while (temp)
		{
			head = head->next;
			free(temp);
			temp = head;
		}
	}
}
