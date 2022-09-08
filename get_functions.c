#include "monty.h"
#include "lists.h"

/**
 * get_functions - selects the right function
 * @parsed: line from the bytecode file passed to main
 *
 * Return: pointer to the selected function, or NULL on failure
 */
void (*get_functions(char **parsed))(stack_t **, unsigned int)
{
	instruction_t func_arr[] = {
		{"push", push_op},
		{"pall", pall_op},
		{"pint", pint_op},
		{"pop", pop_op},
		{"swap", swap_op},
		{"add", add_op},
		{"nop", nop_op},
		{"sub", sub_op},
		{"div", div_op},
		{"mul", mul_op},
		{"mod", mod_op},
		{"pchar", pchar_op},
		{"pstr", pstr_op},
		{"rotl", rotl_op},
		{"rotr", rotr_op},
		{"stack", stack_op},
		{"queue", queue_op},
		{NULL, NULL}
	};

	int codes = 17, i;

	for (i = 0; i < codes; i++)
	{
		if (strcmp(func_arr[i].opcode, parsed[0]) == 0)
		{
			return (func_arr[i].f);
		}
	}
	return (NULL);
}

/**
 * push_op - handles the push instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void push_op(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	int num = 0, i;

	if (data.words[1] == NULL)
	{
		dprintf(STDERR_FILENO, PUSH_FAIL, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	for (i = 0; data.words[1][i]; i++)
	{
		if (isalpha(data.words[1][i]) != 0)
		{
			dprintf(STDERR_FILENO, PUSH_FAIL, line_number);
			free_all(1);
			exit(EXIT_FAILURE);
		}
	}
	num = atoi(data.words[1]);

	if (data.qflag == 0)
		new = add_d_node(stack, num);
	else if (data.qflag == 1)
		new = add_d_node_end(stack, num);
	if (!new)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * pall_op - handles the pall instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void pall_op(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if (*stack)
		print_d_linked(*stack);
}
