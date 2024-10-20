#include <stdio.h>

#define MAXCHAR 1024

void escape(char s[], char t[]) {
    int i = 0;
    for(i = 0; s[i] != '\0'; ++i) {
        t[i] = s[i];
    }
    t[i] = '\0';

    int c, j;
    j = 0;
    while((c = t[j]) != '\0')  {
        switch(c) {
            case '\t':
                putchar('\\');
                putchar('t');
                break;

            case '\n':
                putchar('\\');
                putchar('n');
                break;

            case '\r':
                putchar('\\');
                putchar('r');
                break;

            case '\v':
                putchar('\\');
                putchar('v');
                break;

            default: 
                putchar(c);
        }

        ++j;
    }
}

void count() {
    int i, c, nwhite, ndigits[10], nother;
    nother = nwhite = 0;

    for(int i = 0; i < 10; ++i) {
        ndigits[i] = 0;
    }

    while((c = getchar()) != EOF) {
        switch(c) {
            case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
                ndigits[c - '0']++;
                break;

            case ' ':
            case '\t':
            case '\n':
                nwhite++;
                break;

            default:
                nother++;
        }
    }

    for(int i = 0; i < 10; ++i) {
        printf("%d\n", ndigits[i]);
    }
    printf("Total whitespaces: %d\n", nwhite);
    printf("Total other chars: %d\n", nother);

}

int main() {
    // count();

    char dest[MAXCHAR];
    char src[] = "cat\n\r\t\vt";

    escape(src, dest);
    return 0;
}
