#include "monty.h"

global_v gv = {NULL, NULL, 0};

int free_memory(stack_t *stack, FILE *file, char *linebuf, int exit_status);


/**
 * free_memory- free all allocated memory within the program
 * and returns exit status.
 * @stack: stack to deallocate
 * @file: pointer to an opened file to be closed
 * @linebuf: Line buffer for read bytecode file
 * @exit_status: the exit code the program exits with
 *
 * Return: EXIT_SUCCESS on success, respective error code on failure.
 */
int free_memory(stack_t *stack, FILE *file, char *linebuf, int exit_status)
{
	free_stack(&stack);

	if (file)
		fclose(file);
	if (linebuf && *linebuf == 0)
	{
		free(linebuf);
		return (malloc_error());
	}

	free(linebuf);
	return (exit_status);
}


/**
 * read_file - Reads and executes monty bytecodes script.
 * @file: File pointer to an open Monty bytecodes script.
 *
 * Return: EXIT_SUCCESS on success, respective error code on failure.
 */
int read_file(FILE *file)
{
	stack_t *stack = NULL;
	char *buffer = NULL;
	int exit_status = EXIT_SUCCESS;
	size_t length = 0;
	unsigned int line_number = 0;
	void (*op_func)(stack_t**, unsigned int);
	char *garg[2] = {NULL, NULL};

	if (init_stack(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	while (getline(&buffer, &length, file) != -1)
	{
		line_number++;
		garg[0] = strtok(buffer, DELIMS);
		gv.op_cmd = garg[0];
		if (garg[0] && garg[0][0] != '#')
		{
			op_func = handle_operation(gv.op_cmd);
			if (op_func == NULL)
			{
				free_stack(&stack);
				exit_status = unknown_opcode(garg[0], line_number);
				break;
			}
			garg[1] = strtok(NULL, DELIMS);
			if (!garg[1] && strcmp(garg[0], "push") == 0)
			{
				exit_status = int_error(line_number);
				break;
			}
			else
				gv.op_arg = garg[1];
			op_func(&stack, line_number);
			if (gv.errno != 0)
			{
				exit_status = gv.errno;
				break;
			}

		}
	}
	return (free_memory(stack, file, buffer, exit_status));
}

/**
 * main - the entry point for Monty Interp
 *
 * @argc: the count of arguments passed to the program
 * @argv: Argument vector.
 *
 * Return: (EXIT_SUCCESS) on success (EXIT_FAILURE) on error
 */
int main(int argc, char *argv[])
{
	FILE *file = NULL;
	int exit_status = EXIT_SUCCESS;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	exit_status = read_file(file);
	return (exit_status);
}
