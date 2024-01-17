#include "monty.h"
/**
 * exec_push_instructoin - exectutes push operation \
 * to stack given  the operand.
 * @line_number: line number where the operand is in file.
 * @stack: memory to store the operand using.
 * @opcode_operand: data following opcode that is to \
 * be stored to the memory (stack);
 * Return: 0 for sucess otherwise 1.
 */
int exec_push_instruction(int line_number,
		char *opcode_operand, stack_t **stack)
{
	if (is_valid_push_operand(opcode_operand, line_number) != 0)
		return (1);
	if (push_el_to_stack(stack, atoi(opcode_operand)) != 0)
		return (1);
	return (0);
}
