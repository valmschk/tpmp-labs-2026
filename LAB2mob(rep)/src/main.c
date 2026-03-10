#include <stdio.h>
#include "process.h"

int main() {
    FILE *f_in = fopen("input.txt", "r");
    FILE *f_out = fopen("output.txt", "w");

    if (f_in == NULL || f_out == NULL) return 1;

    process_file(f_in, f_out);

    fclose(f_in);
    fclose(f_out);
    return 0;
}