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
