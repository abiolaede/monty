#include "monty.h"

void monty_push(stack_t **stack, unsigned int line_number);
void monty_pall(stack_t **stack, unsigned int line_number);
void monty_pint(stack_t **stack, unsigned int line_number);
void monty_pop(stack_t **stack, unsigned int line_number);
void monty_swap(stack_t **stack, unsigned int line_number);

/**
 * monty_push - Pushes a value to a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The instruction line number of a Monty bytecodes file.
 */
void monty_push(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *new;
	int n;

	if (!isonlydigit(gv.op_arg))
	{
		gv.errno = int_error(line_number);
		return;
	}

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		malloc_error();
		return;
	}

	n = atoi(gv.op_arg);
	new->n = n;
	if (check_mode(*stack) == STACK)
	{
		tmp = (*stack)->next;
		new->prev = (*stack);
		new->next = tmp;
		if (tmp)
			tmp->prev = new;
		(*stack)->next = new;
	}
	else
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		new->prev = tmp;
		new->next = NULL;
		tmp->next = new;
	}

}

/**
 * monty_pall - Prints the values of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The instruction line number of a Monty bytecodes file.
 */
void monty_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	(void)line_number;
}

/**
 * monty_pint - Prints the top value of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The instruction line number of a Monty bytecodes file.
 */
void monty_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (temp->next == NULL)
		return;

	printf("%d\n",  temp->next->n);
	(void)line_number;
}

/**
 * monty_pop - Removes the top value element of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list
 * @line_number: The instruction line number of a Monty bytecodes file.
 */
void monty_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *next = NULL;

	if ((*stack)->next == NULL)
	{
		gv.errno = pop_error(line_number);
		return;
	}

	next = (*stack)->next->next;
	free((*stack)->next);
	if (next)
		next->prev = *stack;
	(*stack)->next = next;
}

/**
 * monty_swap - Swaps the top two value elements of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top1 = (*stack)->next;
	stack_t *top2;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		gv.errno = short_stack_error(line_number, "swap");
		return;
	}

	top2 = (*stack)->next->next;
	(*stack)->next->next = top2->next;
	top1->prev = top2;
	if (top2->next)
		top2->next->prev = top1;
	top2->next = top1;
	top2->prev = *stack;
	(*stack)->next = top2;
}
