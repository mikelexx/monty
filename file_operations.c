#include "monty.h"
/**
 * can_open_file - checks and prints if file can be opened:
 * @file: pointer to file location.
 * @filename: name of the file.
 * Return: 0 for sucesses otherwise 1.
 */
int can_open_file(FILE *file, char *filename)
{
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		return (1);
	}
	return (0);
}
/**
 * get_opcode_operand - gets the second word that \
 * follows the opcode from the input stream.
 * @opcode: first word from the input stream.
 * @delim: basis for separating words from input stream.(delimiters)
 * Return: second word(opcode_operand) that follows \
 * first word(opcode) from input stream.
 */
char *get_opcode_operand(char *opcode, const char delim[])
{
	char *opcode_operand = NULL;

	while (opcode != NULL)
	{
		opcode_operand = strtok(NULL, delim);
		return (opcode_operand);
	}
	return (opcode_operand);
}
