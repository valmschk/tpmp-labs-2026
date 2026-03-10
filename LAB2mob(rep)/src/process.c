#include <stdio.h>
#include <ctype.h>
#include "process.h"

void process_file(FILE *in, FILE *out) {
    char ch;
    while ((ch = fgetc(in)) != EOF) {
        fputc(toupper(ch), out);
    }
}