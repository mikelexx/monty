#ifndef _MAIN_H
#define _MAIN_H
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
#define  _GNU_SOURCE
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
extern const char *OPCODES[3];
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
typedef struct cmd_s
{
	int arg; 
	char *opcode;
	int line_number;
	stack_t **head;
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
void parse_input(char *line_ptr,int line_number, stack_t **head);
void run(cmd_t *cmd);
void push(cmd_t *cmd);
void pall(cmd_t *cmd);
void pint(cmd_t *cmd);
#endif
