#include <stdio.h>

/* getbits: get n bits from position p (right-adjusted) */ 
unsigned int getbits(unsigned int x, int p, int n) {
    return (x >> (p+1-n)) & ~(~0 << n);
}

// setbits: set n number of bits in x from the pos p to the rightmost n bits of y
unsigned int setbits(int n, int x, int p, int y) {
    x = (x >> (p+1-n) | ~(~0 << n) & y) << 2;
    return x;
}

int main() {
    // bitwise AND: &
    // bitwise inclusive OR: |
    // bitwise exclusive OR (or) XOR I guess: ^
    // left shift: <<
    // right shift: >>
    // one's complement(unary operator): ~
    // These operations can only be performed on integral operands => char, short, int, long

    int x = 20;
    int y = 15;

    printf("%d\n", getbits(x, 4, 3));
    // printf("%d\n", setbits(3, x, 4, y));
    return 0;
}
