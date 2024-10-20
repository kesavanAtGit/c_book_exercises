#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAXVAL 100

void printStackHead();
void duplicateStackHead();
void swapStackHead();
void clearStack();
void printStackElements();
double atod(char [], int pos);
void getop(char []);
void push(double);
double pop(void);
double last_printed_value = 0;

char s[MAXVAL];
int idx = 0;

int main() {
    while(1) {
        getop(s);
        idx = 0;
    }
    return 0;
}

void add() {
    push(pop() + pop());
}

void sub() {
    double op1 = pop();
    push(pop() - op1);
}

void mul() {
    push(pop() * pop());
}

void divide() {
    double op2 = pop();
    if (op2 != 0.0) { 
        push(pop() / op2);
    } else {
        printf("ERROR: zero divisor\n");
    }
}

void modulo() {
    double op2 = pop();
    if (op2 != 0.0) { 
        push((int)pop() % (int)op2);
    } else {
        printf("ERROR: zero divisor\n");
    }
}

void sine() {
    push(sin(pop()));
}

void power() {
    double op1 = pop();
    push(pow(pop(), op1));
}

void exponent() {
    push(exp(pop()));
}

int sp = 0;
double val[MAXVAL];

void push(double f) {
    if (sp < MAXVAL) {
        val[sp++] = f;
    } else
        printf("ERROR: stack full, can't push %g\n", f);
}

double pop(void) {
    if (sp > 0) {
        return val[--sp];
    } else {
        printf("ERROR: stack empty, can't pop.\n");
        return 0.0;
    }
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

    printf("---------------------\n");
    for(int i = 0; i < sp; ++i) {
        printf("VAL[%d] : %g\n", i, val[i]);
    }
    printf("---------------------\n");
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


double atod(char s[], int pos) {
    return (s[pos] - 'a') + 1.0;
}

void getop(char s[]) {
    char buf[MAXVAL];
    size_t len, n;
    n = getline(&s, &len, stdin);

    while(s[idx] != '\n') {
        int i = 0;
        while((buf[i] = s[idx]) == ' ' || (buf[i] = s[idx]) == '\t')
            ++idx;

        if(buf[i] == '+') {
            add();
            ++idx;
            continue;
        }

        if(buf[i] == '-' && !isdigit(s[idx + 1])) {
            sub();
            ++idx;
            continue;
        }

        if(buf[i] == '*') {
            mul();
            ++idx;
            continue;
        }

        if(buf[i] == '/') {
            divide();
            ++idx;
            continue;
        }

        if(buf[i] == '%') {
            modulo();
            ++idx;
            continue;
        }

        if(buf[i] == '~') {
            sine();
            ++idx;
            continue;
        }

        if(buf[i] == '^') {
            power();
            ++idx;
            continue;
        }

        if(buf[i] == '>') {
            printf("LAST PRINTED VALUE: %g\n", last_printed_value);
            ++idx;
            continue;
        }

        if(buf[i] == 'E') {
            exponent();
            ++idx;
            continue;
        }

        if(buf[i] == 'H') {
            printStackHead();
            buf[i] = '\0';
            ++idx;
            continue;
        }

        if(buf[i] == 'D') {
            duplicateStackHead();
            buf[i] = '\0';
            ++idx;
            continue;
        }

        if(buf[i] == 'S') {
            swapStackHead();
            ++idx;
            continue;
        }
        
        if(buf[i] == 'C') {
            clearStack();
            ++idx;
            continue;
        }

        if(buf[i] == 'P') {
            printStackElements();
            ++idx;
            continue;
        }

        if(buf[i] == '$') {
            printf("End of file reached.....\n");
            buf[i] = '\0';
            exit(-1);
        }

        // handle chars a-z
        if(isalpha(buf[i]) && islower(buf[i]) && islower(buf[i])) {
            push(atod(buf, i));
            ++i, ++idx;

            while(isalpha(buf[i] = s[idx])) {
                push(atod(buf, i));
                ++i, ++idx;
            }
            buf[i] = '\0';
            continue;
        }

        // handle negative, positive, fractional numbers and unknown characters
        if(s[idx] == '-') {
            ++idx;
            ++i;
        }else if(!isdigit(buf[i]) && buf[i] != '.' && buf[i] != '-' && !isalpha(buf[i])) {
            printf("Not a valid char: %c\n", s[i]);
            ++idx;
            continue;
        }

        if(isdigit(s[idx])) {
            while(isdigit(buf[i] = s[idx])) {
                ++i, ++idx;
            }
        }

        if(s[idx] == '.') {
            ++i, ++idx;
            while(isdigit(buf[i] = s[idx])) {
                ++i, ++idx;
            }
        }

        buf[i] = '\0';
        push(atof(buf));
        buf[0] = '\0';
    }
}
