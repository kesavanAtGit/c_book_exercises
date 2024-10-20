#include <stdio.h>
#include <string.h>

#define MAXLEN 1000

int getLine(char s[], int max_len) {
    int i, c;
    for(i = 0; i < max_len - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }

    if(c == '\n') {
        s[i++] = c;
    }

    s[i] = '\0';
    return i;
}

int strindex(char s[], char t[]) {
    int i, j, k, idx;
    for(i = strlen(s) - 1;  i >= 0; --i) {
        for(j = i, k = strlen(t) - 1; k >= 0 && s[j] == t[k]; --j, --k) {
        }
        if(k < 0) {
            return i - (strlen(t) - 1);
        }
    }
    return -1;
}

int main() {
    char s[MAXLEN] = {};
    char t[] = "van";

    while(getLine(s, MAXLEN) > 0) {
        printf("%d\n", strindex(s, t));
    }
    return 0;
}
