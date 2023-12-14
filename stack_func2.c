#include "monty.h"

/**
 * nop - Does nothing
 * @stack: pointer to a pointer pointing to top node of the stack
 * @line_number: Integer representing the line number of the opcode.
*/
void nop(stack_t **stack, unsigned int line_number)
{
	if (stack != NULL && *stack != NULL)
	{
		(void)stack;
		(void)line_number;
	}
}

/**
 * swap_nodes - swaps the top two elements of the stack.
 * @stack: pointer to a pointer pointing to top node of the stack.
 * @line_number: Integer representimg the line number of the opcode.
*/
void swap_nodes(stack_t **stack, unsigned int line_number)
{
	stack_t *second_node;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "swap");

	second_node = (*stack)->next;
	(*stack)->next = second_node->next;

	if (second_node->next != NULL)
		second_node->next->prev = *stack;

	second_node->next = *stack;
	(*stack)->prev = second_node;
	second_node->prev = NULL;
	*stack = second_node;
}

/**
 * add_nodes - Adds the top two elements of the stack.
 * @stack: pointer to a pointer pointing to top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
*/
void add_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;
	stack_t *current;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "add");

	current = *stack;
	*stack = (*stack)->next;

	sum = current->n + (*stack)->n;
	(*stack)->n = sum;

	free(current);
	(*stack)->prev = NULL;
}

/**
 * sub_nodes - Adds the top two elements of the stack.
 * @stack: pointer to a pointer pointing to top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
*/
void sub_nodes(stack_t **stack, unsigned int line_number)
{
	int difference;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_err(8, line_number, "sub");

	(*stack) = (*stack)->next;
	difference = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = difference;

	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * div_nodes - Adds the top two elements of the stack
 * @stack:  pointer to a pointer pointing to top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
*/
void div_nodes(stack_t **stack, unsigned int line_number)
{
	int quotient;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "div");

	if ((*stack)->n == 0)
		more_err(9, line_number);

	(*stack) = (*stack)->next;
	quotient = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = quotient;

	free((*stack)->prev);
	(*stack)->prev = NULL;
}
