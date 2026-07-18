#include <stdio.h>
#include "calc.h"

#define MAXOP 100

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

    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '*':
                push(pop() * pop());
                break;
            case '/':
                op2 = pop();
                if (op2 != 0)
                    push(pop() / op2);
                else
                    printf("Error, division by 0.\n");
                break;
            case '\n':
                printf("%.8g\n", pop());
                break;
            default:
                printf("error: unknows operator %s\n", s);
                break;
        }
    }

    return 0;
}
