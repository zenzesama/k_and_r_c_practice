#include <stdio.h>

#define MAXLINE 1000

int get_line_length(char length[], int maxline);
void copy(char to[], char from[]);

int main() {
    int len, max;

    char line[MAXLINE] = "This is the first line.\n This is the second line.\n This is the third line.";
    char longest[MAXLINE];

    max = 0;
    
    while((len = get_line_length(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0) {
        printf("The longest line is:\n %s", longest);
    }

    return 0;
}

int get_line_length(char s[], int lim) {
   int c, i;

   for (i =  0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
       s[i] = c;
   }

   if (s[i] == '\n') {
       s[i] = c;
       i++;
   }

   s[i] = '\0';
   return i;
}

void copy(char to[], char from[]) {
    int i = 0;
    
    while (from[i] != '\0') {
        to[i] = from[i];
        i++;
    }
    to[i] = '\0';
}
