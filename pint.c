#include "monty.h"

/**
 * pint - Prints the value at the top of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number in the script file.
 *
 * Description: Prints the top value of the stack if it's not empty.
 * Exits with failure if the stack is empty.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
