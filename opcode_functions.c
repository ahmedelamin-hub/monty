#include "monty.h"

/**
 * push - Pushes an element to the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Current line number in the script file.
 * @n: The integer to push onto the stack.
 *
 * Description: Allocates a new node
 */
void push(stack_t **stack, unsigned int line_number, int n)
{
	stack_t *new_node;

	(void) line_number; /* Unused parameter */

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}

/**
 * pall - Prints all the values on the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Current line number in the script file.
 *
 * Description: Prints all the values on the stack
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void) line_number; /* Unused parameter */

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

