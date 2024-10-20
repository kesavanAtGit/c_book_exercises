#include <stdio.h>

/* rotate the bits of x by n number of pos */
unsigned int rightrot(unsigned int x, int n) {
    for(int i = 0; i < n; ++i) {
        if(x & 1) {
            x = (x >> 1) | ~(~0 >> 1);
        }else {
            x = x >> 1;
        }
    }
    return x;
}

int main() {
    int x = 0b00001100;
    printf("%d\n", rightrot(x, 3));
    return 0;
}

