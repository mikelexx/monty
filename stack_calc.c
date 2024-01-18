#include "monty.h"
/**
 * add - adds the two top elements of stack.
 * Description: The result is stored in the second \
 * top element of the stack, and the top element is removed,
 * so that at the end: \
 * The top element of the stack contains the result
 * The stack is one element shorter
 * @cmd: object storing the stack information.
 */
void add(cmd_t *cmd)
{
	stack_t **head = cmd->head;
	stack_t *first, *second;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short", cmd->line_number);
		exit(EXIT_FAILURE);
	}
	first = *head;
	second = (*head)->next;
	second->n += first->n;
	pop(cmd);
}
