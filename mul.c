/* mul.c */

#include "monty.h"

void mul(stack_t **stack, unsigned int line_number) {
    int product;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL) {
        fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    product = (*stack)->next->n * (*stack)->n;
    pop(stack, line_number);
    (*stack)->n = product;
}

