#include "monty.h"

void monty_stack(stack_t **stack, unsigned int line_number);
void monty_queue(stack_t **stack, unsigned int line_number);

/**
 * monty_stack - Sets the format of the data to a stack (LIFO)..
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The instruction line number of a Monty bytecodes file.
 */
void monty_stack(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = STACK;
	(void)line_number;
}

/**
 * monty_queue - Sets the format of the data to a queue (FIFO).
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The instruction line number of a Monty bytecodes file.
 */
void monty_queue(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = QUEUE;
	(void)line_number;
}
