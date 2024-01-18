/* opcode_functions.c */

#include "monty.h"

/* Implementations of pint, pop, swap, add, nop */

void pint(stack_t **stack, unsigned int line_number) {
    if (stack == NULL || *stack == NULL) {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", (*stack)->n);
}

void pop(stack_t **stack, unsigned int line_number) {
    stack_t *temp;

    if (stack == NULL || *stack == NULL) {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = *stack;
    *stack = (*stack)->next;
    if (*stack != NULL)
        (*stack)->prev = NULL;

    free(temp);
}

void swap(stack_t **stack, unsigned int line_number) {
    int temp;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL) {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = (*stack)->n;
    (*stack)->n = (*stack)->next->n;
    (*stack)->next->n = temp;
}

void add(stack_t **stack, unsigned int line_number) {
    int sum;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL) {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    sum = (*stack)->n + (*stack)->next->n;
    pop(stack, line_number);
    (*stack)->n = sum;
}

void nop(stack_t **stack, unsigned int line_number) {
    /* To avoid unused parameter warnings */
    (void) stack;
    (void) line_number;

    /* This function doesn't do anything. */
}

