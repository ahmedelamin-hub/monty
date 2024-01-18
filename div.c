#include "monty.h"

/**
 * div_stack - Divides the second top element by the top element of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Current line number in the script file.
 *
 * Description: If the stack contains less than two elements
 */
void div_stack(stack_t **stack, unsigned int line_number)
{
	int result;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->next->n / (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = result;
}
