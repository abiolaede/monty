#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

#define STACK 0
#define QUEUE 1
#define DELIMS " \n\t\a\b"

/**
* struct global_var - this structure contains all our global variable
* @op_arg: argument passed to push
* @op_cmd: opcode
* @errno: exit status
*
* Description: carries values through the program
*/
typedef struct global_var
{
	char *op_cmd;
	char *op_arg;
	int errno;
}  global_v;

extern global_v gv;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* monty.c*/
int read_file(FILE *file);
void (*handle_operation(char *opcode))(stack_t **, unsigned int);

/* data_format.c */
void monty_stack(stack_t **stack, unsigned int line_number);
void monty_queue(stack_t **stack, unsigned int line_number);

/* monty_ops1.c */
void monty_push(stack_t **stack, unsigned int line_number);
void monty_pall(stack_t **stack, unsigned int line_number);
void monty_pint(stack_t **stack, unsigned int line_number);
void monty_pop(stack_t **stack, unsigned int line_number);
void monty_swap(stack_t **stack, unsigned int line_number);

/* monty_ops2.c */
void monty_add(stack_t **stack, unsigned int line_number);
void monty_nop(stack_t **stack, unsigned int line_number);
void monty_sub(stack_t **stack, unsigned int line_number);
void monty_div(stack_t **stack, unsigned int line_number);
void monty_mul(stack_t **stack, unsigned int line_number);

/* monty_ops3.c */
void monty_mod(stack_t **stack, unsigned int line_number);
void monty_pchar(stack_t **stack, unsigned int line_number);
void monty_pstr(stack_t **stack, unsigned int line_number);
void monty_rotl(stack_t **stack, unsigned int line_number);
void monty_rotr(stack_t **stack, unsigned int line_number);

int isonlydigit(char *s);

/* stack.c */
int init_stack(stack_t **stack);
int check_mode(stack_t *stack);
void free_stack(stack_t **stack);

/* error_1.c */
int unknown_opcode(char *opcode, unsigned int line_number);
int int_error(unsigned int line_number);
int malloc_error(void);
int pop_error(unsigned int line_number);
int short_stack_error(unsigned int line_number, char *op);

/* error_2.c */
int pchar_error(unsigned int line_number, char *message);

#endif /* monty.h */
