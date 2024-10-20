#include <stdio.h>
#include <ctype.h>

#define MAXLEN 1000
#define NUMBER '9'
#define BUFSIZE 100

int getch(void);
void ungetch(int c);

// TODO: rewrite this using pointers
int getop(char s[]) {
    int i, c;
    i = 0;

    while ((*s = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';

    // if the digit is negative
    if(c == '-') {
        *s = '-';
    }else if (!isdigit(c) && c != '.')
        return c;

    if(*s == '-') {
        while (isdigit(*s++ = c = getch()))
            ;
    }else if(isdigit(c)) {
        while (isdigit(*s++ = c = getch()))
            ;
    }

    if (c == '.') 
        while (isdigit(*s++ = c = getch()))
            ;

    *s++ = '\0';
    if (c != EOF)
        ungetch(c);

    return NUMBER;
}

char buf[BUFSIZE];
int bufp = 0;

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

int main() {
    char s[MAXLEN];
    printf("%d\n", getop(s));
    return 0;
}
