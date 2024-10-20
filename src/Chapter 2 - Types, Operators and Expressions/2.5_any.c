#include <stdio.h>
#include <string.h>

// strpbrk does the same job but we're so free that we're going to write this function ourselves
int any(char s1[], char s2[]) {
    int i;

    for(i = 0; s1[i] != '\0'; ++i) {
        if(s1[i] == s2[i]) {
            return i + 1;
        }
    }
    return -1;
}

int main() {
    char s1[] = "monkeys";
    char s2[] = "bananums";

    // they both do the same thing
    char* pos_ptr = strpbrk(s2, s1);
    printf("%c\n", *pos_ptr);

    int pos = any(s1, s2);
    printf("Pos is: %d and the char is: %c\n", pos, s1[pos - 1]);
    return 0;
}
