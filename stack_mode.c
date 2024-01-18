#include "monty.h"
/**
 * set_stack_mode - sets the format of the data \
 * to a stack (LIFO). This is the default \
 * behavior of the program.
 * @cmd: object holding info about stack.
 */
void set_stack_mode(cmd_t *cmd)
{
	*cmd->status = 0;
}
