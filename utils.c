#include "monty.h"

/**
 * handle_error - Handles errors by printing a message and exiting.
 * @message: Error message to be printed.
 * @line_number: Line number where the error occurred.
 *
 * Description: Prints an error message to stderr and exits with failure.
 */
void handle_error(const char *message, unsigned int line_number)
{
	fprintf(stderr, "L%d: %s\n", line_number, message);
	exit(EXIT_FAILURE);
}
