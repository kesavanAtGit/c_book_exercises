#include <stdio.h>

void itoa(int n, char s[]) {
    static int i;
    i = 0;

    if(n < 0) {
        putchar('-');
        n = -n;
    }

    if(n / 10) {
        itoa(n / 10, s);
    }

    s[i++] = n % 10 + '0';
    s[i]  = '\0';

}

int main() {
    char s[32];
    itoa(123, s);

    printf("%s\n", s);
    return 0;
}
