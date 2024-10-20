#include <stdio.h>

#define TABSTOP 4
#define MAXCOLUMN 10

// fold when found the last non-blank character before the n-th column of input
// handle the whitespaces as well you baka
void fold() {
    int c, line_pos, lastNonBlankCharPos;
    line_pos = lastNonBlankCharPos = 0;

    while((c = getchar()) != EOF) {
        if(c == '\t') {
            line_pos += 4;
        }else {
            ++line_pos;
        }

        if(line_pos < MAXCOLUMN) {
            if(c != ' ' && c != '\t') {
                lastNonBlankCharPos = line_pos;
            }
        }

        if(line_pos > (MAXCOLUMN - 1) && lastNonBlankCharPos <= (MAXCOLUMN - 1)) {
            putchar('\n');
            lastNonBlankCharPos = 0;
            line_pos = 1;
        }

        if(c == '\n') {
            line_pos = lastNonBlankCharPos = 0;
        }

        putchar(c);
    }
}

void entab() {
    int c, line_pos, blanks;
    blanks = line_pos = 0;

    while((c = getchar()) != EOF) {

        // foo__bar
        if(c == ' ') {
            ++blanks;
            ++line_pos;

            if(line_pos % TABSTOP == 0 && blanks == 4) {
                putchar('\t');
                blanks = line_pos = 0;
            }
        }else {
            line_pos = 0;

            // this sets the blanks to 0
            while(blanks) {
                putchar(' ');
                --blanks;
            }

            if(c == '\n') {
                line_pos = 0;
            }

            putchar(c);
        }
    }
}

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
    // entab();

    fold();
    return 0;
}
