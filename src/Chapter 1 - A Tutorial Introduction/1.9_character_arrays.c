#include <stdio.h>

#define MAXLINE 1000

int getLine(char line[], int maxline);
void copy(char dest[], char src[]);

int getLine(char line[], int limit) {
    int c, i;

    for(i = 0; i < limit - 1 && ((c = getchar())) != EOF && c != '\n'; ++i) {
        // read the char into the array
        line[i] = c;
    }

    if(c == '\n') {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';
    return i;
}

void copy(char dest[], char src[]) {
    int i = 0;

    // hello\n
    while((dest[i] = src[i]) != '\0') {
        ++i;
    }
}

int main() { 
    // Exercise 1.16 revised
    int len, max;
    len = max = 0;

    char line[MAXLINE];
    char longest[MAXLINE];

    while((len = getLine(line, MAXLINE)) > 0) {
        if(len > max) {
            max = len;
            copy(longest, line);
        }

        if(max > 0) {
            printf("%s", longest);
        }
    }

    return 0; 
}
