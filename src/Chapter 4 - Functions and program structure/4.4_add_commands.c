#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void printStackTopTwoElements();
void duplicateStackTopTwoElements();
void swapStackTopTwoElements();
void clearStack();
void printStackElements();

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
            case NUMBER:
                push(atof(s));
                break;

            case '+':
                push(pop() + pop());
                break;

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

            case 'p':
                printStackTopTwoElements();
                break;

            case 'P':
                printStackElements();
                break;

            case 'd':
                duplicateStackTopTwoElements();
                break;

            case 's':
                swapStackTopTwoElements();
                break;

            case 'c':
                clearStack();
                break;

            case '\n':
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

void printStackTopTwoElements() {
    if(!sp) {
        printf("STACK EMPTY \n");
        return;
    }
    printf("Top element: %g, Top second element: %g\n", val[sp - 1], val[sp - 2]);
}

void printStackElements() {
    if(!sp) {
        printf("STACK EMPTY \n");
        return;
    }

    for(int i = 0; i < sp; ++i) {
        printf("VAL[%d] : %g\n", i, val[i]);
    }
}

void duplicateStackTopTwoElements() {
    if(!sp) {
        printf("STACK EMPTY, can't duplicate \n");
        return;
    }

    double push_first, push_second;

    push_first = val[sp - 1];
    push_second = val[sp - 2];

    val[sp++] = push_second;
    val[sp++] = push_first;

    for(int i = sp - 1; i >= 0; --i) {
        printf("ELEMENT %d: %g\n", i, val[i]);
    }
}

void swapStackTopTwoElements() {
    if(!sp) {
        printf("STACK EMPTY, can't swap \n");
        return;
    }

    double temp = val[sp - 1];

    val[sp - 1] = val[sp - 2];
    val[sp - 2] = temp;
}

void clearStack() {
    if(!sp) {
        printf("STACK ALREADY EMPTY \n");
        return;
    }

    for(int i = 0; i < sp - 1; ++i) {
        val[i] = 0;
    }
    sp = 0;
}

/* pop: pop and return top value from stack */
double pop(void) {
    if (sp > 0) {
        return val[--sp];
    } else {
        printf("ERROR: stack empty, can't pop \n");
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

    // printf("RESULTING STR: %s\n", s);
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
