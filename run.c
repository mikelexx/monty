#include "monty.h"
/**
 * run - executes command that corresponds to the opcode \
 * given.
 * @cmd: object that contains data needed by run function.
 */
void run(cmd_t *cmd)
{
	int i = 0;

	instruction_t instructions[] = {{"push", push},
		{"pall", pall},
		{"pint", pint}};
	while (instructions[i].opcode)
	{
		if (strcmp(instructions[i].opcode, cmd->opcode) == 0)
		{
			instructions[i].f(cmd);
			return;
		}
		i++;
	}
	printf("L%d: unknown instruction %s", cmd->line_number, cmd->opcode);
	exit(EXIT_FAILURE);
}
