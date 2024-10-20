#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

#define MAXOP 100

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

            case '\n':
                printf("RESULT: %g\n", pop());
                break;

            default:
                printf("ERROR: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}
