/* main.c */

#include "monty.h"
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *file;
    char line[1024]; /* Assuming a reasonable maximum line length */

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
        /* Remove newline character from fgets */
        line[strcspn(line, "\n")] = 0;
        /* Parse and execute each line */
    }

    fclose(file);
    return 0;
}

