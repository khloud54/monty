#include "monty.h"

/**
 * add - Sums the top two elements of the stack,
 * places the result int the second top element,
 * and eliminates the top element.
 * @stack: Reference to the stack
 * @line_number: Line number where the add opcode is executed
 *
 * Return: No output
*/
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp_ptr;
	unsigned int len = 0;

	temp_ptr = *stack;

	while (temp_ptr != NULL)
	{
		temp_ptr = temp_ptr->next;
		len++;
	}

	if (len < 2)
		err(9, NULL, *stack, NULL, NULL, line_number);

	(*stack)->next->n = (*stack)->next->n + (*stack)->n;

	pop(stack, line_number);
}

/**
 * nop - Has no effect
 * @stack: Reference to the stack
 * @line_number: Line number where the nop opcode is executed
 *
 * Return: No output
*/
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * sub - Subtracts the top element from the second top element in the stack
 * @stack: Reference to the stack
 * @line_number: Line number where the sub opcode is located in the
 * opcode file
 * Return: No output
*/
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	unsigned int len = 0;

	temp = *stack;

	while (temp != NULL)
	{
		temp = temp->next;
		len++;
	}

	if (len < 2)
		err(10, NULL, *stack, NULL, NULL, line_number);

	(*stack)->next->n = (*stack)->next->n - (*stack)->n;

	pop(stack, line_number);
}

/**
 * divide - Divides the second top element by
 * the top element.
 * @stack: The stack
 * @line_number: Line number where the div opcode interpreted.
 * Return: No output
*/
void divide(stack_t **Stack, unsigned int line_number)
{

	stack_t *temp;
	unsigned int len = 0;

	temp = *stack;
	while (temp != NULL)
	{
		temp = temp->next;
		len++;
	}

	if (len < 2)
		err_handle_more(11, NULL, *stack, NULL, NULL, line_number);

	if ((*stack)->n == 0)
		err_handle_more(12, NULL, *stack, NULL, NULL, line_number);

	(*stack)->next->n = (*stack)->next->n / (*stack)->n;

	pop(stack, line_number);
}

/**
 * mul - Multiplies the second top element of the stack by
 * the top element of the stack
 * @stack: Reference to the stack
 * @line-number: Line number where the mul opcode is interpreted
 *
 * Return: Nothing
*/
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	unsigned int len = 0;

	temp = *stack;
	while (temp != NULL)
	{
		temp = temp->next;
		len++;
	}

	if (len < 2)
		err_handle_more(13, NULL, *stack, NULL, NULL, line_number);

	(*stack)->next->n = (*stack)->next->n * (*stack)->n;

	pop(stack, line_number);
}
