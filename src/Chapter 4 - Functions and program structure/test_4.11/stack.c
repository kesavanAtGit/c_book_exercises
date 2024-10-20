#include <stdio.h>
#include "calc.h"

#define MAXVAL 100

static double val[MAXVAL];
static int sp = 0;

void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
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
