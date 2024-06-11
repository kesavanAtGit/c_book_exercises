#include <stdio.h>

#define ARR_SIZE 10
#define CHAR_ARR_SIZE 128

// the first and last character in the character set
#define NUL 0
#define DEL 127

void frequencyOfChars() {
    int c, nchars[CHAR_ARR_SIZE];

    for(int i = 0; i < CHAR_ARR_SIZE; ++i) {
        nchars[i] = 0;
    }

    while((c = getchar()) != EOF) {
        if(c >= NUL && c <= DEL) {
            ++nchars[c];
        }
    }

    for(int j = 0; j < CHAR_ARR_SIZE; ++j) {
        printf("Char %d: Frequency: %d\n", j, nchars[j]);
    }
}

// a vertical histogram would be more challenging; that's why i didn't do it
void wordLengthHistogram() {
    int c, previousChar, wordLength;
    wordLength = 0;
    previousChar = EOF;

    int nwords[ARR_SIZE];

    for(int i = 0; i < ARR_SIZE; ++i) {
        nwords[i] = 0;
    }

    int idx = 0;
    while((c = getchar()) != EOF) {
        if(c == ' ' || c == '\t' || c == '\n') {
            if(previousChar != ' ' && previousChar != '\t' && previousChar != '\n') {
                nwords[idx++] = wordLength;
                wordLength = 0;
            }
        }else {
            ++wordLength;
        }
        previousChar = c;
    }

    printf("Word: \t");
    for(int j = 0; j < ARR_SIZE; ++j) {
        printf("%d\t", j + 1);
    }
    printf("\n");

    printf("Size: \t");
    for(int k = 0; k < ARR_SIZE; ++k) {
        printf("%d\t", nwords[k]);
    }
}

// counts digits, whitespaces and all other characters
void count() {
    int c, nwspaces, nothers;
    nwspaces = nothers = 0;
    int ndigits[ARR_SIZE];

    for(int i = 0; i < ARR_SIZE; ++i) {
        ndigits[i] = 0;
    }

    while((c = getchar()) != EOF) {
        if(c >= '0' && c <= '9') {
            ++ndigits[c - '0'];
        }else if(c == ' ' || c == '\t' || c == '\n') {
            ++nwspaces;
        }else {
            ++nothers;
        }
    }

    for(int i = 0; i < ARR_SIZE; ++i) {
        printf("Digit %d: %d occurences\n", i + 1, ndigits[i]);
    }

    printf("WhiteSpaces: %d\n Other Characters: %d\n", nwspaces, nothers);
}

int main() {
    // count();
    // wordLengthHistogram();
    frequencyOfChars();
    return 0;
}
