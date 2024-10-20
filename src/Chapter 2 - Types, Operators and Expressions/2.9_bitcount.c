#include <stdio.h>

/* Exercise 2-9. In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit
in x. Explain why. Use this observation to write a faster version of bitcount. */

// cause the representation of -1 in 2's complement is all 1s and doing & with the rightmost 1-bit deletes it
int bitcount(int x) {
    int count = 0;

    while (x != 0) {
        x &= (x - 1);
        ++count;
    }

    return count;
}

int main() {
    printf("%d\n", bitcount(7));
    return 0;
}
