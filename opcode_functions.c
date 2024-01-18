/* opcode_functions.c */

#include "monty.h"

/* Implementations of pint, pop, swap, add, nop */

void push(stack_t **stack, unsigned int line_number, int n) {
    stack_t *new_node;

    (void) line_number; /* Unused parameter */

    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = n;
    new_node->prev = NULL;
    new_node->next = *stack;
    if (*stack != NULL)
        (*stack)->prev = new_node;
    *stack = new_node;
}

void pall(stack_t **stack, unsigned int line_number) {
    stack_t *current = *stack;

    (void) line_number; /* Unused parameter */

    while (current != NULL) {
        printf("%d\n", current->n);
        current = current->next;
    }
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

