#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define SIZE 32
#define BUFSIZE 100

double getfloat(double* n);
int getch(void);
void ungetch(int);

double getfloat(double* n) {
    int c, sign;

    while(isspace(c = getch()))
        ;

    if(!isdigit(c) && c != EOF && c != '.' && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }

    sign = (c == '-')? -1 : 1;
    if(c == '+' || c == '-') {
        c = getch();
        if(!isdigit(c)) {
            ungetch(c);
            return 0;
        }
    }

    for(*n = 0; isdigit(c);) { 
        *n = 10 * *n + (c - '0');
        c = getch();
    }

    double place, power;
    place = 1;
    if(c == '.') {
        // 12.40
        c = getch();
        for(*n; isdigit(c);) {
            *n = 10 * *n + (c - '0');
            power = pow(10, place);
            ++place;
            c = getch();
        }
    }

    *n = sign * (*n/ power);
    printf("%g\n", *n);

    if(c != EOF) {
        ungetch(c);
    }
    return c;
}


int main() {
    int n; 
    double array[SIZE];

    getfloat(&array[0]);

    /*
    for(n = 0; n < SIZE && (getfloat(&array[n]) != EOF); ++n)
        ;

    for(int i = 0; i < n; ++i) {
        printf("%g\n", array[i]);
    }
    */

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

