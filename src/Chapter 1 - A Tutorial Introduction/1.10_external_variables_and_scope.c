#include <stdio.h>

#define TABSTOP 4
#define MAXCOLUMN 80

// Replace strings of blanks with tabs and spaces to suffice the blanks
void entab() {
    int c, previousChar, count;
    previousChar = EOF;
    count = 0;

    while((c = getchar()) != EOF) {
        if(c == ' ') {
            ++count;

            while((c = getchar()) != EOF) {
            }
        }else {
            putchar(c);
        }
    }
}

// Replace tabstops with blanks
void detab() {
    int c;

    while((c = getchar()) != EOF) {
        if(c == '\t') {
            for(int i = 0; i < TABSTOP; ++i) {
                putchar(' ');
            }
        }else {
            putchar(c);
        }
    }
}

int main() {
    // detab();
    entab();
    return 0;
}
