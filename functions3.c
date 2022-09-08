#include "monty.h"
#include "lists.h"

/**
 * rotl_op - handles the rotl instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void rotl_op(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int num  = 0;

	(void)line_number;

	if (*stack == NULL)
		return;
	temp = get_d_node_index(*stack, 0);
	num = temp->n;
	delete_d_node_index(stack, 0);
	add_d_node_end(stack, num);
}

/**
 * rotr_op - handles the rotr instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void rotr_op(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int num = 0, len = d_linked_len(*stack);

	(void)line_number;

	if (*stack == NULL)
		return;
	temp = get_d_node_index(*stack, len - 1);
	num = temp->n;
	delete_d_node_index(stack, len - 1);
	add_d_node(stack, num);
}

/**
 * stack_op - handles the stack instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void stack_op(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	data.qflag = 0;
}


/**
 * queue_op - handles the queue instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void queue_op(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	data.qflag = 1;
}
