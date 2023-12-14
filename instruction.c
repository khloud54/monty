#include "monty.h"

/**
 * get_op_f - Selects the correct function to perform an operation
 * @opcode: The operation code to be performed
 *
 * Return: A pointer to the function corresponding to the opcode
*/
void (*get_op_f(char *opcode))(stack_t **stack, unsigned int line_number)
{
	int i;
	instruction_t opcodes[] = {
		{"pint", pint},
		{"pall", pall},
		{"swap", swap},
		{"pop", pop},
		{"nop", nop},
		{"add", add},
		{"sub", sub},
		{"mul", mul},
		{"div", divide},
		{"mod", mod},
		{"pstr", pstr},
		{"pchar", pchar},
		{NULL, NULL}
	};

	i = 0;

	while (opcodes[i].opcode != NULL)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
			return (opcodes[i].f);
		i++;
	}

	return (NULL);
}
