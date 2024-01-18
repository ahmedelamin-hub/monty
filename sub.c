#include "monty.h"

/**
 * sub - Subtracts the top element from the second top element of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number in the script file.
 *
 * Description: Subtracts the top element from the second top
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int difference;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	difference = (*stack)->next->n - (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = difference;
}
