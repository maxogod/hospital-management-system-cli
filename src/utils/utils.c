#include <stdio.h>
#include "./utils.h"

int lines_in_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        return -1;
    }

    int line_count = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            line_count++;
        }
    }

    fclose(file);
    return line_count;
}
