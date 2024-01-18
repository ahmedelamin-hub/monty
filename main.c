/* main.c */

#include "monty.h"
#include <string.h>
#include <ctype.h>

void execute_command(const char *command, stack_t **stack, unsigned int line_number);

int main(int argc, char *argv[]) {
    FILE *file;
    char line[1024];
    char *token;
    unsigned int line_number = 0;
    stack_t *stack = NULL;

    if (argc != 2) {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        line_number++;
        token = strtok(line, " \n");

        
        if (token == NULL || token[0] == '#') {
            continue;
        }

        execute_command(token, &stack, line_number);
    }

    fclose(file);
    return 0;
}

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

