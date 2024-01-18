#include "monty.h"
/**
 * nop - does nothing.
 * @cmd: object containing nop opcode.
 */
void nop(cmd_t *cmd)
{
	(void)cmd;
}
/**
 * pall - prints all elements of stack:
 * @cmd: object containing the stack.
 */
void pall(cmd_t *cmd)
{
	stack_t  *curr;

	curr = *cmd->head;
	if (curr == NULL)
		return;
	while (curr != NULL)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
}
/**
 * pint - print topmost element of stack.
 * @cmd: object containing the stack.
 */
void pint(cmd_t *cmd)
{
	stack_t **head, *curr;

	head = cmd->head;
	curr = *head;
	if (curr == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", cmd->line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", curr->n);
}
