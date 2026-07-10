#include <stdio.h>
#include "calc.h"

int sp = 0;
double stk[MAXVAL];

void push(double val) {
    if (sp < MAXVAL) {
        stk[sp++] = val;
    }
    else {
        printf("Error. Stack is full. Can't add %lf.\n", val);
    }
}

double pop() {
    if (sp > 0) {
        return stk[--sp];
    }
    else {
        printf("Error. Stack is empty. Can't pop.\n");
        return 0.0;
    }
}
