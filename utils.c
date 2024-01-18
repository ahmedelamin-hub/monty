/* utils.c */

#include "monty.h"

void handle_error(const char *message, unsigned int line_number) {
    fprintf(stderr, "L%d: %s\n", line_number, message);
    exit(EXIT_FAILURE);
}

