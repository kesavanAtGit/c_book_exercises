#include <stdio.h>
#include <ctype.h>

#define SIZE 32
#define BUFSIZE 100

int getint(int* n);
int getch(void);
void ungetch(int);

int getint(int* n) {
    int c, sign;

    while(isspace(c = getch()))
        ;

    if(!isdigit(c) && c != EOF && c != '+' && c != '-') {
        // we push the character back onto the input if it is not a digit and return 0
        ungetch(c);
        return 0;
    }

    sign = (c == '-')? -1 : 1;
    if(c == '+' || c == '-') {
        if(!isdigit(c = getch())) {
            // do we need to push the sign onto the input as well?
            ungetch(c);
            return 0;
        }
    }

    for(*n = 0; isdigit(c), c = getch();) {
        *n = 10 * *n + (c - '0');
    }
    *n *= sign;

    if(c != EOF) {
        ungetch(c);
    }

    return c;
}

int main() {
    int n, array[SIZE];
    for(n = 0; n < SIZE && (getint(&array[n]) != EOF); ++n)
        ;

    for(int i = 0; i < n; ++i) {
        printf("%d\n", array[i]);
    }

    return 0;
}

char buf[BUFSIZE];
int bufp = 0;

int getch(void) {
    return (bufp > 0)? buf[--bufp]: getchar();
}

void ungetch(int c) {
    if(bufp >= BUFSIZE) {
        printf("Cannot put the character back onto the input. BUFFER full\n");
        return;
    }
    buf[bufp++] = c;
}
