#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int max);
int str_index(char source[], char searchfor[]);

char pattern[] = "machine";

int main() {
    char line[MAXLINE];
    int found = 0;

    while (get_line(line, MAXLINE) > 0) {
        if (str_index(line, pattern) >= 0) {
            printf("%s", line);
            found++;
        }
    }

    return found;
}


// this loads the line into s and returns the length
// also checks if length is greater than the size allocated for string
// nul terminates the string as well
// Ctrl + D is the EOF on unix and linux btw
int get_line(char s[], int lim) {
    int c = 0;
    int i = 0;
    
    while (--lim > 0 && (c = getchar()) != EOF && c !='\n') {
        s[i++] = c;
    }

    if (c == '\n') {
        s[i++] = c;
    }

    s[i] = '\0';

    return i;
}


// returns index of t in s, -1 if not available
// outer loop iterates over each character in s.
// inner loop uses index j for s and k for t.
// it stops if t[k] != '\0' (end of t, meaning full match) or if its a mismatch
// after inner loop we reached end of t, it returns the matched index if k reaches end of t
// k reaching end of t means we found a match
int str_index(char s[], char t[]) {
    int i, j, k;

    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++);
        if (t[k] == '\0') return i;
    }

    return -1;
}
