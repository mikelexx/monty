#include "monty.h"
/**
 * set_queue_mode - sets the format of the data to a queue (FIFO).
 * @cmd: data holding information about the stack.
 */
void set_queue_mode(cmd_t *cmd)
{
	*cmd->status = 1;
}
/**
 * handle_queue_mode - configues structure to FIFO format.
 * @new: stack_t object.
 * @cmd: holds info about stack.
 * @h: head of stack.
 */
void handle_queue_mode(stack_t **new, cmd_t *cmd, stack_t **h)
{
	stack_t *tmp;

	(*new)->n = cmd->arg;
	(*new)->next = NULL;
	(*new)->prev = NULL;
	if (*h == NULL)
	{
		*h = *new;
		return;
	}
	tmp = *h;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *new;
	(*new)->prev = tmp;
}

