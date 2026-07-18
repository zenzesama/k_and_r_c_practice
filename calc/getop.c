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
    if (isdigit(c)) {
        s[i++] = c;
        while (isdigit(s[i++] = (c = getch())));
    }
    
    if (c == '.') {
        s[i++] = c;
        while (isdigit(s[i++] = (c = getch())));
    }

    s[i] = '\0';
    if (c != EOF) ungetch(c);

    return NUMBER;
}
