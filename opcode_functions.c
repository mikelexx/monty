#include "monty.h"
/**
 * is_valid_push_operand - checks if the operand to push opcode is valid.
 * @operand: argument to push opcode.
 * @line_number: line number in the file where the opcode is located at.
 * Return: 0 for succes else 1.
 */
int is_valid_push_operand(char *operand, int line_number)
{
	if (operand == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		return (1);
	}
	if (strcmp(operand, "0") != 0 && atoi(operand) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		return (1);
	}
	return (0);
}
/**
 * is_valid_opcode - checks if the opcode is among the defined valid ones.
 * @line_number: line number of the opcode
 * @opcode: the opcode itself
 * Return: 0 for sucess else 1.
 */
int is_valid_opcode(int line_number, char *opcode)
{
	int i
		;
	for (i = 0; i < 3; i++)
	{
		if (strcmp(opcode, OPCODES[i]) == 0)
		{
			return (0);
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	return (1);
}