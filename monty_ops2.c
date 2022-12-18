#include "monty.h"

void monty_add(stack_t **stack, unsigned int line_number);
void monty_nop(stack_t **stack, unsigned int line_number);
void monty_sub(stack_t **stack, unsigned int line_number);
void monty_div(stack_t **stack, unsigned int line_number);
void monty_mul(stack_t **stack, unsigned int line_number);

/**
 * monty_add - Adds the top two values of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The instruction line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the top second element node
 *              from the top and the top element/value is removed.
 */
void monty_add(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		gv.errno = short_stack_error(line_number, "add");
		return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_nop - Does absolutely nothing for the Monty opcode 'nop'.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The instruction line number of a Monty bytecodes file.
 */
void monty_nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}

/**
 * monty_sub - Subtracts the second element from the top of
 *             a stack_t linked list by the top element/value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The instruction line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second element node
 *              from the top and the top element is removed.
 */
void monty_sub(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		gv.errno = short_stack_error(line_number, "sub");
		return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_div - Divides the second element from the top of
 *             a stack_t linked list by the top element value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The instruction line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second element node
 *              from the top and the top element is removed.
 */
void monty_div(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		gv.errno = short_stack_error(line_number, "div");
		return;
	}

	if ((*stack)->next->n == 0)
	{
		gv.errno = EXIT_FAILURE;
		fprintf(stderr, "L%u: division by zero\n", line_number);
		return;
	}

	(*stack)->next->next->n /= (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_mul - Multiplies the second element from the top of
 *             a stack_t linked list by the top element value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The instruction line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second element node
 *              from the top and the top element is removed.
 */
void monty_mul(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		gv.errno = short_stack_error(line_number, "mul");
		return;
	}

	(*stack)->next->next->n *= (*stack)->next->n;
	monty_pop(stack, line_number);
}
