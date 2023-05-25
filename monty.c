#include "monty.h"

global_t myGlobals;

/**
 * free_myGlobals - frees the global variables
 *
 * Return: no return
 */
void free_myGlobals(void)
{
	free_dlistint(myGlobals.head);
	free(myGlobals.buffer);
	fclose(myGlobals.fd);
}

/**
 * start_myGlobals - initializes the global variables
 *
 * @fd: file descriptor
 * Return: no return
 */
void start_myGlobals(FILE *fd)
{
	myGlobals.lifo = 1;
	myGlobals.cont = 1;
	myGlobals.arg = NULL;
	myGlobals.head = NULL;
	myGlobals.fd = fd;
	myGlobals.buffer = NULL;
}

/**
 * check_input - checks if the file exists and if the file can
 * be opened
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: file struct
 */
FILE *check_input(int argc, char *argv[])
{
	FILE *fd;

	if (argc == 1 || argc > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");

	if (fd == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (fd);
}

/**
 * main - Entry point
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	void (*f)(stack_t **stack, unsigned int line_number);
	FILE *fd;
	size_t size = 256;
	ssize_t nlines = 0;
	char *lines[2] = {NULL, NULL};

	fd = check_input(argc, argv);
	start_myGlobals(fd);
	nlines = getline(&myGlobals.buffer, &size, fd);
	while (nlines != -1)
	{
		lines[0] = _strtoky(myGlobals.buffer, " \t\n");
		if (lines[0] && lines[0][0] != '#')
		{
			f = get_opcodes(lines[0]);
			if (!f)
			{
				dprintf(2, "L%u: ", myGlobals.cont);
				dprintf(2, "unknown instruction %s\n", lines[0]);
				free_myGlobals();
				exit(EXIT_FAILURE);
			}
			myGlobals.arg = _strtoky(NULL, " \t\n");
			f(&myGlobals.head, myGlobals.cont);
		}
		nlines = getline(&myGlobals.buffer, &size, fd);
		myGlobals.cont++;
	}

	free_myGlobals();

	return (0);
}