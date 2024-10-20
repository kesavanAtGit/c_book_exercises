#include <stdio.h>

#define TABSTOP argv[1]

// accept the list of tab stops as arguments. Use default if nothing is given
void entab() {
}

void detab() {
}

int main(int argc, char* argv[]) {
    printf("Hello%sWorld\n", TABSTOP);
    return 0;
}
