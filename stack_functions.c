#include "main.h"
/**
 * push_el_to_stack - appends an element on top of stack
 * @stack: stack data structure for storing stack_t objects
 * @n: data to be stored.
 * Return: 0 for success else EXIT_FAILURE.
 */
int push_el_to_stack(stack_t **stack, int n)
{
	stack_t *curr = *stack, *head;

	curr->n = n;
	head = malloc(sizeof(stack_t));
	if (head == NULL)
	{
		fprintf(stdout, "Error: malloc failed\n");
		return (EXIT_FAILURE);
	}
	head->next = curr;
	curr->prev = head;
	(*stack) = head;
	return (0);
}
/**
 * display_stack - displays stack data.
 * @stack: stack for data structure for storing stack_t objects.
 */
void display_stack(stack_t **stack)
{
	stack_t *tmp = (*stack)->next;

	while (tmp)
	{
		fprintf(stdout, "%d\n", tmp->n);
		tmp = tmp->next;
	}
}
