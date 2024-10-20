/*
   Write a routine ungets(s) that will push back an entire string onto the input.
   Should ungets know about buf and bufp, or should it just use ungetch?
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

void printStackHead();
void duplicateStackHead();
void swapStackHead();
void clearStack();
void printStackElements();
void ungets(char []);
double atod(char []);

#define MAXOP 100
#define NUMBER '0'
#define ALPHA '1'
#define BUFSIZE 100
#define MAXVAL 100

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);
double last_printed_value = 0;

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
                if (op2 != 0.0) { 
                    push(pop() / op2);
                } else {
                    printf("ERROR: zero divisor\n");
                }

                break;

            case '%':
                op2 = pop();
                if(op2 != 0.0) { 
                    push((int)pop() % (int)op2);
                } else { 
                    printf("ERROR: zero divisor\n");
                }
                break;

            case 'H':
                printStackHead();
                break;

            case 'P':
                printStackElements();
                break;

            case 'D':
                duplicateStackHead();
                break;

            case 'S':
                swapStackHead();
                break;

            case 'C':
                clearStack();
                break;

            case '~':
                push(sin(pop()));
                break;

            case '^':
                push(pow(pop(), pop()));
                break;

            case 'e':
                push(exp(pop()));
                break;

            case ALPHA:
                push(atod(s));
                break;

            case '>':
                printf("%g\n", last_printed_value);
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

int sp = 0;
double val[MAXVAL];

void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("ERROR: stack full, can't push %g\n", f);
}

void printStackHead() {
    if(!sp) {
        printf("STACK EMPTY \n");
        return;
    }
    printf("Top element: %g, Top second element: %g\n", val[sp - 1], val[sp - 2]);
    last_printed_value = val[sp - 1];
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

void duplicateStackHead() {
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

void swapStackHead() {
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

double pop(void) {
    if (sp > 0) {
        return val[--sp];
    } else {
        printf("ERROR: stack empty, can't pop.\n");
        return 0.0;
    }
}

double atod(char s[]) {
    return (s[0] - 'a') + 1.0;
}

char ungets_buf[BUFSIZE];
int ungets_bufp = 0;

int getop(char s[]) {
    int i, c;
    i = 0;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';

    if(isalpha(c) && islower(c)){ 
        s[i++] = c;
        s[i] = '\0';
        return ALPHA;
    }

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

    if(isalpha(c) &&c != EOF) {
        ungets_buf[ungets_bufp++] = c;
        while(isalpha(ungets_buf[ungets_bufp++] = c = getch()))
            ;
    }

    // onetwothree
    printf("Ungets Buffer: %s\n", ungets_buf);
    ungets(ungets_buf);
    return NUMBER;
}

char buf[BUFSIZE];
int bufp = 0;

// ungets need not know about the buf and bufp but only the ungetch
void ungets(char ungets_buf[]) {
    for(int i = ungets_bufp - 1; i >= 0; --i) {
        ungetch(ungets_buf[i]);
    }

    printf("BUFFER after ungets(s): %s\n", buf);
}

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

