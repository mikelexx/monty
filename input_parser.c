#include "monty.h"
/**
 * set_operation_mode - sets the operation mode for stack using cmd object.
 * @cmd: object holding opcode and all the operations related to it.
 * @opcode: python opcode.
 * Return: 1 for success else 0.
 */
int set_operation_mode(char *opcode, cmd_t *cmd)
{
	if (opcode == NULL || opcode[0] == '#')
		return (0);
	if (strcmp(opcode, "queue") == 0)
	{
		*cmd->status = 1;
		return (0);
	}

	if (strcmp(opcode, "stack") == 0)
	{
		*cmd->status = 0;
		return (0);
	}
	return (1);
}
/**
 * check_empty_input - checks if the argument to push is empty input.
 * @arg: input to be checked.
 * @line_number: line number that contains the arg.
 */
void check_empty_input(char *arg, unsigned int line_number)
{
	int len = strlen(arg);

	if (len == 1 && arg[0] == '-')
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

}
/**
 * parse_input - tokenizes inputs into opcodes and optional \
 * arguments to and stores the information of each line from \
 * data stream to command object.
 * @lineptr: pointer to line data buffer.
 * @cmd: object storing opcode and its related information.
 * Return: 1 for success otherwise 0.
 */
int parse_input(char *lineptr, cmd_t *cmd)
{
	const char delim[] = " \t\r\n";
	char *arg, *opcode;
	int len;
	unsigned int line_number;

	line_number = cmd->line_number;
	if (!lineptr)
		return (0);
	opcode = strtok(lineptr,  delim);
	if (set_operation_mode(opcode, cmd) == 0)
		return (0);
	if (strcmp(opcode, "push") == 0)
	{
		arg = strtok(NULL, delim);
		if (arg == NULL)
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		len = strlen(arg);
		check_empty_input(arg, cmd->line_number);
		while (len--)
		{
			if (len == 0 && arg[len] == '-')
				break;
			if (arg[len] < 48 || arg[len] > 57)
			{
				fprintf(stderr, "L%u: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
		}
		cmd->arg = atoi(arg);
		cmd->opcode = opcode;
		return (1);
	}
	cmd->opcode = opcode;
	return (1);
}
