#include "main.h"
#include "opcodes.h"
int OPCODES_LEN = 2;
const char *OPCODES[2] = {"push", "pall"};
int is_valid_instruction(int line_number, char *opcode)
{
	int i
		;
	for (i = 0; i < OPCODES_LEN; i++)
	{
		if (strcmp(opcode, OPCODES[i]) == 0)
		{
			return (1);
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n",line_number,opcode);
	return (EXIT_FAILURE);
}
void push_el_to_stack(stack_t **stack, int n )
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
	return;
}
void display_stack(stack_t **stack)
{
	stack_t *tmp = (*stack)->next;
	while (tmp)
	{
		fprintf(stdout, "%d\n", tmp->n);
		tmp = tmp->next;
	}
	return;
}
int main(int argc, char *argv[])
{
	FILE *file;
	char line_input[256];
	const char delim[] = " \n";
	char *first, *second;
	int line_number = 1;
	stack_t *stack = malloc(sizeof(stack_t)); 

	if (argc != 2)
	{
		fprintf(stderr, "Usage %s file\n", argv[0]);
		return (EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	while (fgets(line_input, sizeof(line_input), file) != NULL)
	{
                first = strtok(line_input, delim);
		while (first != NULL)
		{
			second = strtok(NULL, delim);
			break;
		}
		is_valid_instruction(line_number, first);
		if (strcmp(first, "push") == 0)
		{
			if (second == NULL)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				return (EXIT_FAILURE);
			}
			if (strcmp(second, "0") != 0 && atoi(second) == 0)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				return (EXIT_FAILURE);
			}
			push_el_to_stack(&stack, atoi(second));
		}
		if (strcmp(first, "pall") == 0)
		{
			display_stack(&stack);
		}
		line_number++;
	}
	

	fclose(file);
	return (0);
}
