#include <stdio.h>

#define MAXLEN 1000

#define IN_COMMENT 1
#define OUT_COMMENT 0

int getStr(char str[]) {
    int c, i;

    for(i = 0; i < MAXLEN && (c = getchar()) != EOF && c != '\n'; ++i) {
        str[i] = c;
    }

    if(c == '\n') {
        str[i++] = c;
    }

    str[i] = '\0';
    return i;
}

// this is what a newbie's code looks like on a simple problem I guess??
void removeComments(int str_len, char str[]) {
    int state;
    state = OUT_COMMENT;

    for(int i = 0; i < str_len; ++i) {
        if(str[i] == '/' && str[i + 1] == '/') {
            continue;
        }

        if(str[i] == '/' && str[i + 1] == '*') {
            state = IN_COMMENT;
        }

        // the last two commenting characters gets left out, thus getting removed
        if(!state && str[i] != '*' && str[i] != '/') {
            putchar(str[i]);
        }
        
        if(state && str[i] != '/' && str[i] != '*') {
            putchar(str[i]);

            /*dslkjf*/
            if(state && str[i] == '*' && str[i + 1] == '/') {
                state = OUT_COMMENT;
            }
        }
    }
}

int main() {
    char arr[MAXLEN];
    int arr_len;

    arr_len = getStr(arr);
    removeComments(arr_len, arr);

    return 0;
}
