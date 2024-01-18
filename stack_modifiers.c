#include "monty.h"
/**
 * push - pushes an element to stack.
 * @cmd: command storing the element and other informations \
 * like line_number on which it's located in bytecode .
 */
void push(cmd_t *cmd)
{
	stack_t **h, *new = NULL;

	h = cmd->head;
	if (h == NULL)
	{
		fprintf(stderr, "L%d: push integer\n", cmd->line_number);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		exit(EXIT_FAILURE);
	}
	new->n = cmd->arg;
	if (*h == NULL)
	{
		new->prev = NULL;
		new->next = NULL;
		*h = new;
		return;
	}
	(*h)->prev = new;
	new->next = *h;
	new->prev = NULL;
	*h = new;
}
/**
 * pop - removes the top element of the stack.
 * @cmd: contains the head of stack.
 */
void pop(cmd_t *cmd)
{
	stack_t *tmp = NULL;
	stack_t **head = cmd->head;

	if (*head == NULL || head == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", cmd->line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	*head = (*head)->next;
	free(tmp);
}
