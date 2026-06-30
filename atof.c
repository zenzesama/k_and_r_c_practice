#include <stdio.h>
#include <ctype.h>

#define MAXLEN 1000;

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

    return sign * val / power;

}

int main() {
    char[MAXLEN] s;
    int i = 0, limit = MAXLEN;

    

    printf("%lf\n", atof("6.76767676767676767"));

    return 0;
}
