/* mod.c */

#include "monty.h"

void mod(stack_t **stack, unsigned int line_number) {
    int remainder;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL) {
        fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    if ((*stack)->n == 0) {
        fprintf(stderr, "L%d: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }

    remainder = (*stack)->next->n % (*stack)->n;
    pop(stack, line_number);
    (*stack)->n = remainder;
}

