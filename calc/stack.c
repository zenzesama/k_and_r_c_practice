#include <stdio.h>
#include "calc.h"

#define MAXVAL 100

int sp = 0;
double stk[MAXVAL];

void push(double val) {
    if (sp < MAXVAL) {
        stk[sp++] = val;
    }
    else {
        printf("Error. Stack is full. Can't add %lf\n", val);
    }
}

double pop() {
    if (sp > 0) {
        return stk[--sp];
    }
    else {
        printf("Error. Stack is empty, can't pop.\n");
        return 0.0;
    }
}

void clear() {
    while (sp > 0) {
        pop();
    }
}

int is_empty() {
    return sp == 0;
}

double peek() {
    if (sp >= 0) {
        return stk[sp];
    }
    else {
        printf("Error. Stack is empty, can't peek.\n");
        return 0.0;
    }
}
