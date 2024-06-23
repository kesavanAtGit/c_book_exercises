#include <stdio.h>

#define IN 1
#define OUT 0

// Exercise 1.12
void printOneWordPerLine() {
    int currentChar, previousChar;
    previousChar = EOF;

    // hello  world
    while ((currentChar = getchar()) != EOF) {
        if (currentChar == ' ' || currentChar == '\t' || currentChar == '\n') {
            if (previousChar != ' ' && previousChar != '\t' && previousChar != '\n') {
                printf("Current char is: %c and the previous char is: %c", currentChar, previousChar);
                putchar('\n');
            }
        }
        else {
            putchar(currentChar);
        }

        previousChar = currentChar;
    }
}

// exercise 1.11 : Test the word count fn() => Tested
void wordCount() {
    int nlines, nwords, nchars;
    nlines = nwords = nchars = 0;

    int state = OUT;
    int c;

    while ((c = getchar()) != EOF) {
        nchars++;

        if (c == '\n') {
            nlines++;
        }

        if (c == ' ' || c == '\t' || c == '\n') {
            state = OUT;
        } else if (state == OUT) {
            state = IN;
            ++nwords;
        }
    }
    printf("Words:%d, Chars:%d, Newlines:%d", nwords, nchars, nlines);
}

int main() {
    // wordCount();
    printOneWordPerLine();
    return 0;
}
