#ifndef MONTY
#define MONTY
#define _POSIX_C_SOURCE  200809L
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct globals - global structure to use in the functions
 * @lifo: is stack or queue
 * @cont: current line
 * @arg: second parameter inside the current line
 * @head: doubly linked list
 * @fd: file descriptor
 * @buffer: input text
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct globals
{
	int lifo;
	unsigned int cont;
	char  *arg;
	stack_t *head;
	FILE *fd;
	char *buffer;
} global_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern global_t myGlobals;

/* opcode_instructions*/
void _push(stack_t **stack, unsigned int number);
void _pall(stack_t **stack, unsigned int number);
void _pint(stack_t **doubly, unsigned int counter);
void _pop(stack_t **doubly, unsigned int counter);
void _swap(stack_t **doubly, unsigned int counter);
void _queue(stack_t **doubly, unsigned int counter);
void _stack(stack_t **doubly, unsigned int counter);
void _add(stack_t **doubly, unsigned int counter);
void _nop(stack_t **doubly, unsigned int counter);
void _sub(stack_t **doubly, unsigned int counter);
void _div(stack_t **doubly, unsigned int counter);
void _mul(stack_t **doubly, unsigned int counter);
void _mod(stack_t **doubly, unsigned int counter);
void _pchar(stack_t **doubly, unsigned int counter);
void _pstr(stack_t **doubly, unsigned int counter);
void _rotl(stack_t **doubly, unsigned int counter);
void _rotr(stack_t **doubly, unsigned int counter);

/* doubly linked list functions */
stack_t *add_dnodeint_end(stack_t **head, const int n);
stack_t *add_dnodeint(stack_t **head, const int n);
void free_dlistint(stack_t *head);


/*get function*/
void (*get_opcodes(char *opc))(stack_t **stack, unsigned int line_number);

/*imported functions*/
int _sch(char *s, char c);
char *_strtoky(char *s, char *d);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void *_calloc(unsigned int nmemb, unsigned int size);
int _strcmp(char *s1, char *s2);


void free_myGlobals(void);

#endif
