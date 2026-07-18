#include <stdio.h>
#include <ctype.h>
#include "calc.h"

int getop(char *s) {
    int i, c;

    while((c = getch()) == ' ');

    if (!isdigit(c) && c != '.') {
        s[0] = c;
        s[1] = '\0';
        return c;
    }

    i = 0;
    int seen_dot = 0;

    while (isdigit(c) || (c == '.' && !seen_dot)) {
        if (c == '.') seen_dot = 1;

        s[i++] = c;
        c = getch();
    }

    s[i] = '\0';
    if (c != EOF) ungetch(c);

    return NUMBER;
}
