#include <stdio.h>
#include <ctype.h>

#define MAXLEN 1000

double my_pow(double x, int n) {
    if (n == 0) return 1;
    
    double result = 1;

    if (n < 0) {
        x = 1 / x;
        n = -n;
    }

    while (n--) {
        result *= x;
    }
    
    return result;
}

double atof(char *s) {
    int sign = 1;
    double val, power;

    while (isspace(*s)) s++;

    sign = (*s == '-') ? -1 : 1;
    if (*s == '+' || *s == '-') s++;

    for (val = 0.0; isdigit(*s); s++) {
        val = 10.0 * val + (*s - '0');
    }

    if (*s == '.') s++;
    
    for (power = 1; isdigit(*s); s++) {
        val = 10.0 * val + (*s - '0');
        power *= 10;
    }
    
    val *= sign;

    if (*s == 'e' || *s == 'E') {
        s++; // skip the e

        int exp_sign = 1;
        double exp;

        exp_sign = (*s == '-') ? -1 : 1;
        if (*s == '+' || *s == '-') s++;

        for (exp = 0.0; isdigit(*s); s++) {
            exp = 10.0 * exp + (*s - '0');
        }
        
        exp *= exp_sign;
        
        power = power / (my_pow(10, exp));
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
