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
        if (token != NULL && token[0] != '#') {  /* '#' starts a comment line */
            execute_command(token, &stack, line_number);
        }
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
    /* Implement other commands as needed */
}

