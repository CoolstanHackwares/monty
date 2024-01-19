#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

stack_t *head = NULL;

#define BUFFER_SIZE 1024

/**
 * main - The Monty entry point
 * @argn: The args number
 * @args: The args passed to the interpreter
 *
 * Return: ...
 */
int main(int argn, char *args[])
{
	FILE *fd = NULL;
	unsigned int line_num = 1;
	int op_status = 0;
	char *filename = NULL, *op_code = NULL, *op_param = NULL, buff[BUFFER_SIZE];

	filename = args[1];
	check_args_num(argn);
	fd = open_file(filename);

	while (fgets(buff, sizeof(buff), fd) != NULL)
	{
		op_code = strtok(buff, "\t\n ");
		if (op_code)
		{
			if (op_code[0] == '#')
			{
				++line_num;
				continue;
			}
			op_param = strtok(NULL, "\t\n ");
			op_status = handle_execution(op_code, op_param, line_num, op_status);

			if (op_status >= 100 && op_status < 300)
			{
				fclose(fd);
				handle_error(op_status, op_code, line_num, buff);
			}
		}
		++line_num;
	}
	frees_stack();
	fclose(fd);
	return (0);
}
