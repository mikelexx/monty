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
	const char delim[] = " \n";
	char *opcode, *opcode_operand;
	int line_number = 1;
	FILE *file = fopen(argv[1], "r");
	stack_t *stack = malloc(sizeof(stack_t));

	if (argc != 2)
	{
		fprintf(stderr, "Usage %s file\n", argv[0]);
		return (EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (can_open_file(file, argv[1]) != 0)
		return (EXIT_FAILURE);
	while (fgets(line_input, sizeof(line_input), file) != NULL)
	{
		opcode = strtok(line_input, delim);
		opcode_operand = get_opcode_operand(opcode, delim);
		if (is_valid_opcode(line_number, opcode) != 0)
			return (EXIT_FAILURE);
		if (strcmp(opcode, "push") == 0)
		{
			if (exec_push_instruction(line_number, opcode_operand, &stack) != 0)
				return (EXIT_FAILURE);
		}
		if (strcmp(opcode, "pall") == 0)
		{
			display_stack(&stack);
		}
		line_number++;
	}
	fclose(file);
	return (0);
}
