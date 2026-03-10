#include <stdio.h>
#include <stdlib.h>
#include "process.h"
int main() {
    FILE *in = fopen("input.txt", "r");
    FILE *out = fopen("output.txt", "w");
    char buffer[1024];
    if (!in || !out) {
        printf("Error!\n");
        return 1;
    }
    while (fgets(buffer, sizeof(buffer), in)) {
        to_uppercase(buffer);
        fputs(buffer, out);
    }
    fclose(in);
    fclose(out);
    return 0;
}
