#include "monty.h"
/**
 * rotr - rotates the stack to the bottom.
 * @cmd: holds info about the stack.
 */
void rotr(cmd_t *cmd)
{
	stack_t **h  = cmd->head;
	stack_t *first = *h, *second = *h, *third;

	if (h == NULL || *h == NULL || (*h)->next == NULL)
		return;
	if ((*h)->next->next == NULL)
	{
		swap(cmd);
		return;
	}
	while (third->next != NULL)
		third = third->next;
	while (second->next != third)
		second = second->next;
	third->next = first;
	third->prev = first->prev;
	first->prev = third;
	second->next = NULL;
	*h = second;
}
/**
 * rotl - rotates the stack to the top.
 * @cmd: holds info about the stack.
 */
void rotl(cmd_t *cmd)
{
	stack_t **h = cmd->head;
	stack_t *first = *h, *second, *third = *h;

	if (h == NULL || *h == NULL || (*h)->next == NULL)
		return;
	if ((*h)->next->next == NULL)
	{
		swap(cmd);
		return;
	}
	second = (*h)->next;
	while (third->next != NULL)
		third = third->next;
	first->next = third->next;
	first->prev = third;
	third->next = first;
	second->prev = NULL;
	*h  = second;
}
/**
 * swap -swaps the top two elements of the stack.
 * @cmd: contains the address of head of stack.
 */
void swap(cmd_t *cmd)
{
	stack_t **head = cmd->head;
	stack_t *first, *middle, *third;

	if (cmd == NULL ||
			head == NULL || *head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr,
		"L%u: can't swap, stack too short\n", cmd->line_number);
		exit(EXIT_FAILURE);
	}
	first = *head;
	middle = (*head)->next;
	third = (*head)->next->next;
	if (third)
		third->prev = first;
	first->next = third;
	first->prev = middle;
	middle->next = first;
	*head = middle;
}
/**
 * push - pushes an element to stack.
 * @cmd: command storing the element and other informations \
 * like line_number on which it's located in bytecode .
 */
void push(cmd_t *cmd)
{
	stack_t **h, *new = NULL;

	h = cmd->head;
	if (cmd == NULL || h == NULL)
	{
		fprintf(stderr, "L%d: push integer\n", cmd->line_number);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		exit(EXIT_FAILURE);
	}
	if (*cmd->status == 1)
	{
		handle_queue_mode(&new, cmd, h);
		return;
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

	if (cmd == NULL || *head == NULL || head == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", cmd->line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	*head = (*head)->next;
	free(tmp);
}
