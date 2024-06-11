#include <stdio.h>
#include <assert.h>

// the maximum no of chars that can be read from an input
#define MAXCHARS 1000

void copyStringBackwards(char dest[], char src[], int len) {
    int i, idx;
    int newLineCharPos = len - 1;
    idx = 0;

    // hello\n
    for(i = (len - 2); i >= 0; --i) {
        dest[idx++] = src[i];

        // terminate the string
        if(i == 0) {
            dest[idx++] = src[newLineCharPos];
            dest[idx] = '\0';
        }
    }
}

char* reverseString(char dest[], char src[], int len) {
    copyStringBackwards(dest, src, len);
    return dest;
}

// Exercise 1.18
void removeTrailingBlanksTabs() {
    char buf[MAXCHARS];

    int c, idx, previousChar;
    idx = 0;
    previousChar = EOF;

    for(int i = 0; i <= MAXCHARS && ((c = getchar()) != EOF); ++i) {
        if(c == ' ' || c == '\t' || c == '\n') {
            if(previousChar != ' ' && previousChar != '\t') {
                buf[idx++] = c;

                // feh\n\0
                // 012 3 4
                if(c == '\n') {
                    buf[idx] = '\0';
                    // to check the len of the string
                    printf("len:%d", idx);
                    idx = 0;
                }
            }
        }else {
            buf[idx++] = c;
        }

        previousChar = c;
    }

}

// Exercise 1.17
int getLenOfInput(char s[]) {
    int c, i;

    for(i = 0; i <= MAXCHARS && ((c = getchar()) != EOF) && c != '\n'; ++i) {
        s[i] = c;
    }

    if(c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}

int main() {
    char buf[MAXCHARS];
    char reversedStr[MAXCHARS];
    int len = 0;

    while((len = getLenOfInput(buf)) > 0) {
        // printf("Length is %d", len);
        // printf("%s", reverseString(reversedStr, buf, len));
    }

    return 0;
}
