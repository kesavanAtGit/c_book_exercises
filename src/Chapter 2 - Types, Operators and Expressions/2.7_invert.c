#include <stdio.h>

/* invert: invert the n number of bits in x from the pos */
unsigned int invert(int x, int p, int n) {
    return ((x >> (p+1-n) ^ ~(~0 << n))) << 2;
}

int main() {
    int x = 20;
    int y = 15;

    printf("%d\n", invert(x, 4, 3));
    return 0;
}
