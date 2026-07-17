#include <stdio.h>
#include "calc.h"

int main() {
    char exp[MAXVAL], result[MAXVAL];
    int limit = MAXVAL, i = 0;
    char c;

    while (limit-- && (c = getchar()) && c != '\n') {
        exp[i++] = c;
    }
    
    exp[i] = '\0';

    to_postfix(exp, result);

    set_exp(result);



    return 0;
}
