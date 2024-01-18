#ifndef _MONTY_H
#define _MONTY_H
#define  _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
typedef struct cmd_s
{
	int arg, *status; 
	char *opcode;
	unsigned int line_number;
	stack_t **head, **tail;
	
} cmd_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(cmd_t *cmd);
} instruction_t;
int is_valid_arg(char *arg);
int parse_input(char *line_ptr, cmd_t *cmd);
void process_line(char *lineptr, stack_t **head ,stack_t **tail, int *mode, unsigned int line_number);
void run(cmd_t *cmd);
void push(cmd_t *cmd);
void pall(cmd_t *cmd);
void pint(cmd_t *cmd);
void pop(cmd_t *cmd);
void swap(cmd_t *cmd);
void add(cmd_t *cmd);
void nop(cmd_t *cmd);
void sub(cmd_t *cmd);
void divide(cmd_t *cmd);
void mul(cmd_t *cmd);
void mod(cmd_t *cmd);
void pchar(cmd_t *cmd);
void pstr(cmd_t *cmd);
void rotl(cmd_t *cmd);
void rotr(cmd_t *cmd);
int set_operation_mode(char *opcode, cmd_t *cmd);
#endif
