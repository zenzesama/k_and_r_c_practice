#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAXLEN 1000

double atof(char s[]) {
    int i = 0, sign = 1;
    double val, power;

    while (isspace(s[i])) i++;

    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') i++;

    for (val = 0.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
    }

    if (s[i] == '.') i++;
    
    for (power = 1; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    
    val *= sign;

    if (s[i] == 'e' || s[i] == 'E') {
        i++; // skip the e

        int exp_sign = 1;
        int exp;

        exp_sign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-') i++;

        for (exp = 0; isdigit(s[i]); i++) {
            exp = 10 * exp + (s[i] - '0');
        }
        
        exp *= exp_sign;
        
        power = power / (pow(10, exp));
    }

    return val / power;
}

int main() {
    char s[MAXLEN];
    int i = 0, limit = MAXLEN, c;

    while (limit-- && (c = getchar()) != EOF && c != '\n') {
        s[i] = c;
        i++;
    }

    printf("%lf\n", atof(s));

    return 0;
}
