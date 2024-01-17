#include "main.h"
const char *OPCODES[2] = {"push", "pall"};
/**
 * main - interpretes the opcode instructions contained in the bytecode file.
 * @argc: count of arguments to the program main.
 * @argv: list of the arguments passed to program.
 * Return: 0 for sucess else EXIT_FAILURE.
 */
int main(int argc, char *argv[])
{
	char line_input[256];
	FILE *file;
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
		is_valid_opcode(line_number, first);
		if (strcmp(first, "push") == 0)
		{
			is_valid_push_operand(second, line_number);
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
