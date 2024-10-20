#include <stdio.h>
#include <ctype.h>
#include "calc.h"

#define BUFSIZE 100
static char buf[BUFSIZE];
static int bufp = 0;

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if(bufp >= BUFSIZE) {
        printf("Too many characters in the buffer\n");
    }
    buf[bufp++] = c;
}

int getop(char s[]) {
    int i, c;
    i = 0;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';

    if(c == '-') {
        s[i] = '-';
    }else if (!isdigit(c) && c != '.')
        return c;

    if(s[i] == '-') {
        while (isdigit(s[++i] = c = getch()))
            ;
    }else if(isdigit(c)) {
        while (isdigit(s[++i] = c = getch()))
            ;
    }

    if (c == '.') 
        while (isdigit(s[++i] = c = getch()))
            ;

    s[i] = '\0';

    if (c != EOF) {
        ungetch(c);
    }

    return NUMBER;
}
