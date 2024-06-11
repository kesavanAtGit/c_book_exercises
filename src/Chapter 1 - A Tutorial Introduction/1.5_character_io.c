#include <stdio.h>

void printChars() {
    int x;
    while((x = getchar()) != EOF) {
        putchar(x);
    }
}

// Exercise 1.8
void count() {
    int blanks, tabs, nlines;
    int c;

    blanks = tabs = nlines = 0;

    while((c = getchar()) != EOF) {
        if(c == ' ') {
            ++blanks;
        }else if(c == '\t') {
            ++tabs;
        }else if(c == '\n') {
            ++nlines;
        }
    }

    printf("Tabs: %d\nBlanks: %d\nNewlines: %d\n", tabs, blanks, nlines);
}

// Exercise 1.9
void copyInputToOutput() {
    int nblanks = 0;
    int c;

    while((c = getchar()) != EOF) {
        if(c != ' ' && nblanks > 0) {
            putchar(c);
            nblanks = 0;
            continue;
        }

        if(c == ' ' && nblanks > 0) {
            continue;
        }
        
        if(c == ' ' && nblanks == 0) {
            putchar(c);
            ++nblanks;
            continue;
        }
        
        // this stays whatever happens
        putchar(c);
    }
}

// Exercise 1.10
void replaceWithTabsBackSpacesLines() {
    int c;

    while((c = getchar()) != EOF) {
        if(c == '\t') {
            putchar('\\');
            putchar('t');
        }

        if(c == '\b') {
            putchar('\\');
            putchar('b');
        }

        if(c == '\\') {
            putchar('\\');
        }

        if(c == '\n') {
            putchar('\\');
            putchar('n');
        }

        putchar(c);
    }
}

void lineCount() {
    int lc;
    int c;

    lc = 0;

    // complicated this with the for loop I guess this is where a while loop would've been so much better to understand
    for(int i = 0; (c = getchar()) != EOF; ++i) {
        if(c == '\n') {
            lc += 1;
            printf("%d\n", lc);
        }
    }
}

// double can hold up pretty large numbers and so can long
// long live long
void countInput() {
    double nc;

    for(nc = 0; getchar() != EOF; ++nc) {
        printf("%.0f \n", nc);
    }
}

// exercise
int main() {

    // printChars();
    // countInput();
    // lineCount();
    // count();

    replaceWithTabsBackSpacesLines();

    /*
       int c;
       printf("%d\n", EOF);

       it is 1 if getchar() != EOF
       c = (getchar() != EOF);
       printf("%d\n", c);
       putchar(c);
    */

    return 0;
}
