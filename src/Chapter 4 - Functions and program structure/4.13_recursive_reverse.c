#include <stdio.h>
#include <string.h>

void reverse(char s[], int len) {
    static int i = 0;
    static int j;
    j = len;

    if(i < j) {
        int temp = s[j];
        s[j] = s[i];
        s[i] = temp;

        ++i, --j;

        reverse(s, j);
    }
}

int main() {
    char s[32] = "kesavan";

    int str_len;
    str_len = strlen(s) - 1;

    reverse(s, str_len);
    printf("%s\n", s);
    return 0;
}
