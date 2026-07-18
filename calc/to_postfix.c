#include <stdio.h>
#include <ctype.h>
#include "calc.h"

static int sp = 0;
static char stk[MAXVAL];

static int prec(char c) {
    if (c == '/' || c == '*') {
        return 2;
    }
    else if (c == '+' || c == '-') {
        return 1;
    }
    else {
        printf("Invalid character.\n");
        return -1;
    }
}

void to_postfix(char *exp, char *result) {
    int j = 0;
    
    for (int i = 0; exp[i] != '\0'; i++) {
        char c = exp[i];

        if (c == ' ') continue;

        if (isdigit(c)){
            while (isdigit(exp[i]) || exp[i] == '.') {
                result[j++] = exp[i++];
            }
            result[j++] = ' ';
            i--;
        }

        else if (c == '(') {
            stk[sp++] = c;
        }

        else if (c == ')') {
            while (sp > 0 && stk[sp - 1] != '(') {
                result[j++] = stk[--sp];
                result[j++] = ' ';
            }

            if (sp > 0) sp--;
        }

        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (sp > 0 && stk[sp - 1] != '(' && prec(stk[sp - 1]) >= prec(c)) {
                result[j++] = stk[--sp];
                result[j++] = ' ';
            }
            stk[sp++] = c;
        }

        else {
            printf("Invalid character. %c\n", c);
            return;
        }
    }

    while (sp > 0) {
        result[j++] = stk[--sp];
        result[j++] = ' ';
    }

    if (j > 0 && result[j - 1] == ' ') j--;
    
    result[j++] = '\n';
    result[j] = '\0';
}
