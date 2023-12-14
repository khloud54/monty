#include "monty.h"
/**
 * mod - Computes the remainder of dividing the second top element
 * of the stack by the top element of the stack
 * @stack: Reference to the stack
 * @line_number: Line number where the mod opcode is interpreted
 *
 * Return: Nothing
*/
void mod(stack_t **stack, unsigned int line_number)
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
		err_handle_more(14, NULL, *stack, NULL, NULL, line_number);

	if ((*stack)->n == 0)
		err_handle_more(12, NULL, *stack, NULL, NULL, line_number);

	(*stack)->next->n = (*stack)->next->n % (*stack)->n;

	pop(stack, line_number);
}

/**
 * pchar - Prints the char at the top of the stack
 * @stack: The stack
 * @line_number: Line number where the pchar opcode will be interpreted
 *
 * Return: Nothing
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int number;

	if (*stack == NULL)
		err_handle_more(15, NULL, *stack, NULL, NULL, line_number);

	number = (*stack)->n;

	if (number < 65 || (number > 90 && number < 97) || number > 122)
		err_handle_more(16, NULL, *stack, NULL, NULL, line_number);

	printf("%c\n", number);
}

/**
 * pstr - Prints the char at the top of the stack
 * @stack: The stack
 * @line_number: Line number where the pchar opcode will be interpreted
 *
 * Return: Nothing
 */
void pstr(stack_t **Stack, unsigned int line_number)
{
	stack_t *temp;
	int num;
	(void)line_number;

	if (*stack == NULL)
	{
		printf("\n");
		return;
	}

	temp = *stack;

	while (temp != NULL)
	{
		num = temp->n;
		if (num != 0 && ((num >= 65 && num <= 90) || (num >= 97 && num <= 122)))
			printf("%c", num);
		else
			break;
		temp = temp->next;
	}
	printf("\n");
}

