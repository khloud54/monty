#include "monty.h"

/**
 * process_lines - Handles each line
 * @file: The file to be handled
 * @stack: A reference to the stack
 *
 * Return: Nothing
*/
void process_lines(FILE *file, stack_t *stack)
{
	char *line = NULL, *opcode;
	size_t len = 0;
	unsigned int line_number = 0;
	ssize_t read;

	/* read = getline(&line, &len, file); */

	while ((read = getline(&line, &len, file)) > 0)
	{
		line_number++;
		opcode = strtok(line, "\t\n");

		if (opcode != NULL && opcode[0] == '#')
			continue;

		while (opcode != NULL)
		{
			void(*func)(stack_t **stack, unsigned int line_number) = get_op_f(opcode);

			if (strcmp(opcode, "push") == 0)
			{
				int value;
				char *argument = strtok(NULL, " \t\n");

				if (argument == NULL || !is_valid_integer(argument))
					err(5, line, stack, file, NULL, line_number);
				value = atoi(argument);
				push(&stack, line_number, value);
			}
			else if (func == NULL)
				err(3, line, stack, file, opcode, line_number);
			else
				func(&stack, line_number);

			opcode = NULL;
		}
		/* read = getline(&line, &len, file); */
	}
	clean(line, stack, file);
}

/**
 * is_valid_integer - Verifes if the argument is valid
 * @argument: The argument to be validated
 *
 * Return: 0 if not valid, 1 if valid
*/
int is_valid_integer(const char *argument)
{
	if (argument == NULL || *argument == '\0')
		return (0);

	if (*argument == '-' || *argument == '+')
		argument++;

	while (*argument)
	{
		if (!isdigit(*argument))
		{
			return (0);
		}
		++argument;
	}
	return (1);
}
