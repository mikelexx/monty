#include "monty.h"
/**
 * process_line - puts the extracted line information \
 * int and object cmd.
 * @lineptr: pointer to that line.
 * @head: address of head of stack  double linked list \
 * to be filled with \
 * arguments from that line for functions that need args.
 * @tail: tail of that stack double_linked list.
 * @status: mode of operation on the stack, can be stack \
 * or queue mode.
 * @line_number: number of the line from the data stream.
 */
void process_line(char *lineptr, stack_t **head,
		stack_t **tail, int *status, unsigned int line_number)
{
	cmd_t cmd;

	cmd.head = head;
	cmd.tail = tail;
	cmd.line_number = line_number;
	cmd.status = status;
	if (parse_input(lineptr, &cmd) == 1)
		run(&cmd);
}
