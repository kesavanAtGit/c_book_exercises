#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100
#define NUMBER '0' /* symbol indicating that a number is collected */
#define BUFSIZE 100
#define MAXVAL 100 /* maximum depth of val stack */

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

int main() {
    int type = 0;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER: {
                push(atof(s));
                break;
             }

            case '+': {
                  push(pop() + pop());
                  break;
            }

            case '*':
                push(pop() * pop());
                break;

            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
                
            case '/':
                op2 = pop();
                if (op2 != 0.0) push(pop() / op2);
                else printf("ERROR: zero divisor\n");
                break;

            case '%':
                op2 = pop();
                if(op2 != 0.0) push((int)pop() % (int)op2);
                else printf("ERROR: zero divisor\n");
                break;

            case '\n':
                printf("\t%.8g\n", pop());
                break;

            default:
                printf("ERROR: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */

/* push: push f onto value stack */
void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("ERROR: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void) {
    if (sp > 0) {
        return val[--sp];
    } else {
        printf("ERROR: stack empty\n");
        return 0.0;
    }
}

/* getop: get next character or numeric operand */
int getop(char s[]) {
    int i, c;
    i = 0;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';

    // if the digit is negative
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
    if (c != EOF)
        ungetch(c);

    printf("RESULTING STR: %s\n", s);
    return NUMBER;
}

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

/* get a (possibly pushed-back) character */
int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* push character back on input */
void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
