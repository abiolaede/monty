#include "monty.h"

void monty_mod(stack_t **stack, unsigned int line_number);
void monty_pchar(stack_t **stack, unsigned int line_number);
void monty_pstr(stack_t **stack, unsigned int line_number);
void monty_rotl(stack_t **stack, unsigned int line_number);
void monty_rotr(stack_t **stack, unsigned int line_number);

/**
 * monty_mod - Calculates the modulus of the second element from the
 *             top of a stack_t linked list  by the top element value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The isntruction line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second element node
 *              from the top and the top element is removed.
 */
void monty_mod(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		gv.errno = short_stack_error(line_number, "mod");
		return;
	}

	if ((*stack)->next->n == 0)
	{
		gv.errno = EXIT_FAILURE;
		fprintf(stderr, "L%u: division by zero\n", line_number);
		return;
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_pchar - Prints the character in ascii of the top element
 *               node of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The instruction line number of a Monty bytecodes file.
 */
void monty_pchar(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		gv.errno = pchar_error(line_number, "stack empty");
		return;
	}

	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		gv.errno = pchar_error(line_number, "value out of range");
		return;
	}

	printf("%c\n", (*stack)->next->n);
}


/**
 * monty_pstr - Prints string in ascii value of elements
 *				contained in a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The instruction line number of a Monty bytecodes file.
 */
void monty_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n < 128))
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}

	printf("\n");
	(void) line_number;
}

/**
 * monty_rotl - Rotates the top value of a stack_t linked list to the bottom.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The instruction line number of a Monty bytecodes file.
 */
void monty_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	top->next->prev = *stack;
	(*stack)->next = top->next;
	bottom->next = top;
	top->next = NULL;
	top->prev = bottom;

	(void) line_number;
}

/**
 * monty_rotr - Rotates the bottom value of a stack_t linked list to the top's.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The instruction line number of a Monty bytecodes file.
 */
void monty_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	bottom->prev->next = NULL;
	(*stack)->next = bottom;
	bottom->prev = *stack;
	bottom->next = top;
	top->prev = bottom;

	(void) line_number;
}
