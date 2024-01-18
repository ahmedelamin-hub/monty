#include "monty.h"
#include <string.h>
#include <ctype.h>

void execute_command(const char *command, stack_t **stack, unsigned int line_number);

/**
 * main - Entry point for the Monty bytecode interpreter.
 * @argc: Argument count.
 * @argv: Argument vector.
 *
 * Description: Reads a Monty bytecode file and executes commands.
 * Returns: EXIT_FAILURE on errors, otherwise EXIT_SUCCESS.
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char line[1024];
	char *token;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_number++;
		token = strtok(line, " \n");

		if (token == NULL || token[0] == '#')
		{
			continue;
		}

		execute_command(token, &stack, line_number);
	}

	fclose(file);
	return (0);
}

