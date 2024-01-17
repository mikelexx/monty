#include "main.h"
/**
 * push_el_to_stack - appends an element on top of stack
 * @stack: stack data structure for storing stack_t objects
 * @n: data to be stored.
 * Return: 0 for success else 1.
 */
int push_el_to_stack(stack_t **stack, int n)
{
	stack_t *curr = *stack, *head;

	curr->n = n;
	head = malloc(sizeof(stack_t));
	if (head == NULL)
	{
		fprintf(stdout, "Error: malloc failed\n");
		return (1);
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
/**
 * print_stack_top - prints the value at the top of stack.
 * @stack: pointer to a head of stack.
 * @line_number: line number of file containing opcode that caused this \
 * function to be executed.
 * Return: 0 for sucess otherwise 1.
 */
int print_stack_top(stack_t **stack, int line_number)
{
	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		return (1);
	}
	fprintf(stdout, "%d\n", (*stack)->next->n);
	return (0);
}
