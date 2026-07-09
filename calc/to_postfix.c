#include <stdio.h>
#include <ctype.h>
#include "calc.h"

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



void to_postfix(char exp[], char result[]) {
    int j = 0;
    
    clear();

    for (int i = 0; exp[i] != '\0'; i++) {
        char c = exp[i];

        if (c == ' ') continue;

        if (isdigit(c)){
            while (exp[i] != '\0' && isdigit(c)) {
                result[j++] = c;
                i++;
            }
        }

        else if (c == '(') {
            push(c);
        }

        else if (c == ')') {
            while (!is_empty() && peek() != '(') {
                pop();
            }
        }


    }
}
