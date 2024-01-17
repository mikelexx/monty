#include "monty.h"
/**
 * free_list - frees a double linked list "stack" from the memory.
 * @head: head of the linked list.
 */
void free_list(stack_t **head)
{
	stack_t *curr, *tmp;

	curr = *head;
	while (curr)
	{
		tmp = curr;
		curr = curr->next;
		free(tmp);
	}
}
/**
 * main - interpretes the opcode instructions contained in the bytecode file.
 * @argc: count of arguments to the program main.
 * @argv: list of the arguments passed to program.
 * Return: 0 for sucess else EXIT_FAILURE.
 */

int main(int argc, char *argv[])
{
	char *line_ptr;
	int line_number = 1;
	FILE *file = fopen(argv[1], "r");
	ssize_t chars_read;
	size_t n = 0;
	stack_t *head = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((chars_read = getline(&line_ptr, &n, file)) != -1)
	{
		parse_input(line_ptr, line_number,  &head);
		line_number++;

	}
	fclose(file);
	free(line_ptr);
	free_list(&head);
	return (0);
}
