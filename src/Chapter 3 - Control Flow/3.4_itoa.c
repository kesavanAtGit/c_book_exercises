#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <stdint.h>
#include <string.h>
#include <limits.h>

#define MAXSIZE 1000

void reverse(char s[]) {
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void itoa(int64_t n, char s[]) {
    int i, sign;

    // -2147483648 this would fucking fail because it overflows oh my gawwwwd what a fucking idiot I am
    if((sign = n) < 0) {
        n = -n;
    }

    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);

    if(sign < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}

int main() {
    char s[MAXSIZE];

    itoa(pow(-2, (sizeof(int) * 8) - 1), s);
    printf("%s\n", s);

    return 0;
}
