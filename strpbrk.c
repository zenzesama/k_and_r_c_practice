#include <stdio.h>
#include <string.h>

int find_first(char s1[], char s2[]) {
    int s1_size = strlen(s1);
    int s2_size = strlen(s2);

    int s2_set[26];

    for (int i = 0; i < 26; i++) {
        s2_set[i] = 0;
    }

    for (int i = 0; i < s2_size; i++) {
        s2_set[s2[i] - 'a'] = 1;
    }
    
    int found_index = -1;

    for (int i = 0; i < s1_size; i++) {
        if (s2_set[s1[i] - 'a']) {
            found_index = i;
            break;
        }
    }

    return found_index;
}

int main() {
    char s1[] = "dreaditrunfromit";
    char s2[] = "abce";

    printf("Found at %d\n", find_first(s1, s2));

    return 0;
}
