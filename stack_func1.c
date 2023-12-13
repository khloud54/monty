#include "monty.h"


/**
 * add_to_stack - Adds a node to the stack.
 * @new_node: pointer to the new node.
 * @ln: Integer representing the line number of the opcode.
*/
void add_to_stack(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);

	if (head == NULL)
	{
		head = *new_node;
		return;
	}

	(*new_node)->next = head;
	head->prev = *new_node;
	head = *new_node;
}

/**
 * print_stack - Adds a node to the stack.
 * @stack: pointer to a pointer pointing to top node of the stack.
 * @line_number: line number of the opcode.
*/
void print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;

	if (stack == NULL || *stack == NULL)
		exit(EXIT_FAILURE);

	current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * pop_top - Adds a node to the stack.
 * @stack: pointer to a pointer pointing to top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
*/
void pop_top(stack_t **stack, unsigned int line_number)
{
	stack_t *removed_node;

	if (stack == NULL || *stack == NULL)
		more_err(7, line_number);

	removed_node = *stack;
	*stack = removed_node->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(removed_node);
}

/**
 * print_top - prints the top node of the stack.
 * @stack: pointer to a pointer pointing to top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
*/
void print_top(stack_t **stack, unsigned int line_number)
{
	stack_t *top_node;

	if (stack == NULL || *stack == NULL)
		more_err(6, line_number);

	top_node = *stack;

	printf("%d\n", top_node->n);
}
