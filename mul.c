#include "monty.h"

/**
 * mul - Multiplies the top two elements of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number in the script file.
 *
 * Description: Multiplies the top two elements and stores the result in the
 * second top element, then removes the top element. Exits on error.
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int product;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	product = (*stack)->next->n * (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = product;
}
