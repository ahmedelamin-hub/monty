#include "monty.h"
#include <string.h>
#include <ctype.h>

void execute_command(const char *command, stack_t **stack, unsigned int line_number) {
    if (strcmp(command, "push") == 0) {
        char *num_str = strtok(NULL, " \n");
        if (num_str == NULL || !isdigit(num_str[0])) {
            fprintf(stderr, "L%d: usage: push integer\n", line_number);
            exit(EXIT_FAILURE);
        }
        push(stack, line_number, atoi(num_str));
    } else if (strcmp(command, "pall") == 0) {
        pall(stack, line_number);
    }
    if (strcmp(command, "pint") == 0) {
        pint(stack, line_number);
    }
    if (strcmp(command, "pop") == 0) {
        pop(stack, line_number);
    }
    if (strcmp(command, "swap") == 0) {
        swap(stack, line_number);
    }
    if (strcmp(command, "add") == 0) {
        add(stack, line_number);
    }
    if (strcmp(command, "nop") == 0) {
        nop(stack, line_number);
    }
    if (strcmp(command, "sub") == 0) {
        sub(stack, line_number);
    }
    if (strcmp(command, "div") == 0) {
        div_stack(stack, line_number);
    }
    if (strcmp(command, "mul") == 0) {
        mul(stack, line_number);
    }
    if (strcmp(command, "mod") == 0) {
        mod(stack, line_number);
    }
}
