#include "monty.h"



/**
 * handle_operation - MAtchees an opcode with its corresponding function.
 * @opcode: The opcode to check.
 *
 * Return: A pointer to the coresponding function.
 */
void (*handle_operation(char *opcode))(stack_t **, unsigned int)
{
	int i;

	instruction_t op_funcs[] = {
		{"push", monty_push},
		{"pall", monty_pall},
		{"pint", monty_pint},
		{"pop", monty_pop},
		{"swap", monty_swap},
		{"add", monty_add},
		{"nop", monty_nop},
		{"sub", monty_sub},
		{"div", monty_div},
		{"mul", monty_mul},
		{"mod", monty_mod},
		{"pchar", monty_pchar},
		{"pstr", monty_pstr},
		{"rotl", monty_rotl},
		{"rotr", monty_rotr},
		{"stack", monty_stack},
		{"queue", monty_queue},
		{NULL, NULL}
	};
	i = 0;

	while (op_funcs[i].opcode)
	{
		if (strcmp(opcode, op_funcs[i].opcode) == 0)
			return (op_funcs[i].f);
		i++;
	}
	return (NULL);
}
