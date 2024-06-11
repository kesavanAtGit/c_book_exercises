#include <stdio.h>

// by default arguments passed are temporarily stored and cannot modify the original value of the arguments
int doSomething(int n) {
    return n - 1;
}

int main() {
    int n = 3;
    printf("The value of n before the function call: %d\n", n);

    doSomething(n);

    // no change can be seen cause it is pass by value not pass by reference
    printf("The value of n after the function call: %d\n", n);

    return 0;
}
