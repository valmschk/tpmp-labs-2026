#include <ctype.h>
#include "process.h"
void to_uppercase(char *str) {
    while (*str) {
        *str = (char)toupper((unsigned char)*str);
        str++;
    }
}
