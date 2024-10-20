#include <stdio.h>
#include <string.h>

// delete every character in s1 that matches in s2
void squeeze(char s1[], char s2[]) {
    int i, j;

    for(i = j = 0; s1[i] != '\0'; ++i) {
        if(s1[i] != s2[i]) {
            s1[j++] = s1[i];
        }
    }
    s1[j] = '\0';
}

int main() {
    char s1[] = "boom";
    char s2[] = "kesavan";

    squeeze(s1, s2);
    printf("%s\n", s1);
    return 0;
}
