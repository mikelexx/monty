#include "monty.h"
/**
 * mod - computes the rest of the division \
 * of the second top element of \
 * the stack by the top element of the stack.
 * Description:The result is stored in the \
 * second top element of the stack, and the \
 * top element is removed, so that at the end
 * @cmd: holds all relevant info needed by add opcode
 */
void mod(cmd_t *cmd)
{
	stack_t **head =  cmd->head;

	if (cmd == NULL || head == NULL || *head == NULL ||
			(*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short", cmd->line_number);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L<%u: division by zero", cmd->line_number);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n %= (*head)->n;
	pop(cmd);
}
/**
 * mul - multiplies the second top element of \
 * the stack by the top element of the stack.
 * Description:The result is stored in the \
 * second top element of the stack, and the \
 * top element is removed, so that at the end
 * @cmd: holds all relevant info needed by add opcode
 */
void mul(cmd_t *cmd)
{
	stack_t **head =  cmd->head;

	if (cmd == NULL || head == NULL || *head == NULL ||
			(*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short", cmd->line_number);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n *= (*head)->n;
	pop(cmd);
}
/**
 * divide - divides the second top element of \
 * the stack by the top element of the stack.
 * Description:The result is stored in the \
 * second top element of the stack, and the \
 * top element is removed, so that at the end
 * @cmd: holds all relevant info needed by add opcode
 */
void divide(cmd_t *cmd)
{
	stack_t **head = cmd->head;

	if (cmd == NULL || head == NULL || *head == NULL ||
			(*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short", cmd->line_number);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero", cmd->line_number);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n /= (*head)->n;
	pop(cmd);
}
/**
 * sub -  subtracts the top element of the \
 * stack from the second top element of the stack.
 * Description: The result is stored in the second \
 * top element of the stack, and the top element is \
 * removed, so that at the end:The top element of \
 * the stack contains the result and The stack is \
 * one element shorter.
 * @cmd: stores necessary information for the sub opcode
 */
void sub(cmd_t *cmd)
{
	stack_t **head = cmd->head;

	if (cmd == NULL || head == NULL || *head == NULL
			|| (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short", cmd->line_number);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n -= (*head)->n;
	pop(cmd);
}

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

	if (cmd == NULL || head == NULL ||
			*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short", cmd->line_number);
		exit(EXIT_FAILURE);
	}
	first = *head;
	second = (*head)->next;
	second->n += first->n;
	pop(cmd);
}
