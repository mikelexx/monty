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

int main(int argc, char *argv[])
{
	FILE *file;
	char line_input[256];
	const char delim[] = " \n";
	char *first, *second;
	int line_number = 1;

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
		}
		
	}

	fclose(file);
	return (0);
}


	




