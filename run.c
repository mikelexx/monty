#include "monty.h"
/**
 * run - executes command that corresponds to the opcode \
 * given.
 * @cmd: object that contains data needed by run function.
 */
void run(cmd_t *cmd)
{

	instruction_t instructions[] = {
		{"push", push}, {"pall", pall},
		{"pint", pint}, {"pop", pop},
		{"swap", swap}, {"add", add},
		{"nop", nop}, {"sub", sub},
		{"div", divide}, {"mul", mul},
		{"mod", mod}, {"pchar", pchar},
		{"pstr", pstr}, {"rotl", rotl}
	};
	size_t i = 0;
	size_t len = sizeof(instructions) / sizeof(instructions[0]);

	while (i < len)
	{
		if (strcmp(instructions[i].opcode, cmd->opcode) == 0)
		{
			instructions[i].f(cmd);
			return;
		}
		i++;
	}
	fprintf(stderr,
			"L%u: unknown instruction %s\n", cmd->line_number, cmd->opcode);
	exit(EXIT_FAILURE);
}
