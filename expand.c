#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1000

int max(int a, int b) {
    if (a > b) {
        return a;
    }
    else {
        return b;
    }
}

int min(int a, int b) {
    if (a > b) {
        return b;
    }
    else {
        return a;
    }
}

void expand(char s1[], char s2[]) {
    int s1_size = strlen(s1);

    int left = -1, right = -1;
    for (int i = 0; i < s1_size; i++) {
        if (s1[i] != '-') {
            left = i;
            break;
        }
    }

    for (int j = s1_size - 1; j >= 0; j--) {
        if (s1[j] != '-') {
            right = j;
            break;
        }
    }

    // printf("Left and right and s1_size are %d, %d, %d\n", left, right, s1_size);

    int s1_itr, s2_itr;
    s1_itr = left;
    for (s2_itr = 0; s2_itr < left; s2_itr++) {
        s2[s2_itr] = s1[s2_itr];
    }
    
    while (s1_itr < right) {
        if (s1[s1_itr] == '-') {
            char prev = s1[s1_itr - 1];
            char next = s1[s1_itr + 1];
            
            for (char ch = prev + 1; ch < next; ch++) {
                s2[s2_itr++] = ch;
            }

            s1_itr++;
        }
        else {
            s2[s2_itr++] = s1[s1_itr];
            s1_itr++;
        }
    }

    if (s1[right] != '-' || right != s1_size - 1) {
        for (int temp = right; temp < s1_size; temp++) {
            s2[s2_itr++] = s1[temp];
    
        }
    }

    s2[s2_itr] = '\0';
}

int main() {
    char s1[MAX_SIZE];
    
    int i = 0, c = 0;
    
    while ((c = getchar()) != EOF && c != '\n') {
        s1[i++] = c;
    }

    s1[i] = '\0';

    char s2[MAX_SIZE];
    
    expand(s1, s2);
    printf("This is the extention: %s\n", s2);

    return 0;
}
