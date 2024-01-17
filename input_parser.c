#include "monty.h"
/**
 * parse_input - tokenizes inputs into opcodes and optional \
 * arguments to and stores the information of each line from \
 * data stream to command object.
 * @lineptr: pointer to line data buffer.
 * @line_number: line number from which data is coming from.
 * @head: head of stack.
 */
void parse_input(char *lineptr, int line_number, stack_t **head)
{
	const char delim[] = " \t\n";
	char *arg, *opcode;
	int len;
	cmd_t cmd;

	cmd.head = head;
	cmd.line_number = line_number;
	opcode = strtok(lineptr,  delim);
	if (strcmp(opcode, "push") == 0)
	{
		arg = strtok(NULL, delim);
		if (arg == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		len = strlen(arg);
		while (len > 0)
		{
			if (arg[len - 1] < 48 || arg[len - 1] > 57)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
			len--;
		}
		cmd.arg = atoi(arg);
	}
	cmd.opcode = opcode;
	run(&cmd);
}
