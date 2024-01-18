#include "monty.h"
/**
 * pstr - prints string at top of stack
 * @cmd: stores integer value for which chars will be printed in that range.
 */
void pstr(cmd_t *cmd)
{
	stack_t **head = cmd->head;

	if (*head == NULL)
	{
		printf("\n");
	}
	while (*head && ((*head)->n <= 127 && (*head)->n > 0))
	{
		printf("%c", (*head)->n);
		*head = (*head)->next;
	}
	printf("\n");
}
/**
 * nop - does nothing.
 * @cmd: object containing nop opcode.
 */

void nop(cmd_t *cmd)
{
	(void)cmd;
}

/**
 * pchar -prints the first char at the top of stack.
 * @cmd: holds all the stack containgn the char to \
 * be printed.
 */
void pchar(cmd_t *cmd)
{
	stack_t **head = cmd->head;

	if (head == NULL || *head == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty", cmd->line_number);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n < 0 || (*head)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range", cmd->line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*head)->n);
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
