#include <stdio.h>

#define BUFFSIZE 100

static char buff[BUFFSIZE];
static int buff_ptr = 0;
static char *exp;

void set_exp(char *s) {
    exp = s;
}

int getch(void) {
    if (buff_ptr > 0) {
        return buff[--buff_ptr];
    }
    return (exp && *exp) ? *exp++ : EOF;
}

void ungetch(int c) {
    if (buff_ptr >= BUFFSIZE) 
        printf("buffer is filled\n");
    else 
        buff[buff_ptr++] = c;
}
