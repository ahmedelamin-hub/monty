#include "monty.h"

/**
 * nop - No operation function.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number in the script file.
 *
 * Description: Does nothing. Used to avoid unused parameter warnings.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	/* These casts are to avoid unused parameter warnings */
	(void) stack;
	(void) line_number;
}
