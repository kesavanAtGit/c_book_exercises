#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define BUFSIZE 10
#define MAXOP 32
#define NUMBER '0'

void push(int c);
int pop(void);

char buf[BUFSIZE];
int bufp = 0;

int getop(char* argv, char* str) {
    int i = 0;

    if(argv[0] == '-') {
        *str++ = argv[0];
        ++i;
    }

    if(isdigit(argv[i])) {
        while((isdigit(*str++ = argv[i++]))) {
        }
    }else {
        return argv[i];
    }
    *str = '\0';

    return NUMBER;
}

void push(int c) {
    if(bufp >= BUFSIZE) {
        printf("Buffer is full, can't push\n");
        return;
    }
    buf[bufp++] = c;
}

int pop(void) {
    if(bufp == 0) {
        printf("No elements in the buffer to pop \n");
        return 0;
    }
    return buf[--bufp];
} 

void printStackElements() {
    if(bufp == 0) {
        printf("No elements in the stack\n");
        return;
    }
    printf("----------------\n");
    for(int i = 0; i < bufp; ++i) {
        printf("%d\n", buf[i]);
    }
    printf("----------------\n");
}

int main(int argc, char *argv[]) {
    char str[MAXOP];
    int type, i;
    i = 1;

    while (i < argc) {
        type = getop(*++argv, str);
        int op;

        switch(type) {
            case NUMBER:
                push(atof(str));
                break;

            case '+':
                push(pop() + pop());
                break;

            case '-':
                op = pop();
                push(pop() - op);
                break;

            case '*':
                push(pop() * pop());
                break;

            case '/':
                op = pop();
                if (op == 0) {
                    printf("Zero division is not possible");
                    return -1;
                }
                push(pop() / op);
                break;

            case '%':
                op = pop();
                if (op == 0) {
                    printf("Zero division is not possible");
                    return -1;
                }
                push(pop() % op);
                break;

            case 'P':
                printStackElements();
                break;

            default: 
                printf("Invalid character \n");
                break;
        }
        ++i;
    }

    return 0;
}
