#include <stdio.h>

// preprocesor
// #include => include the contents of a file during compilation
// #define => replaces a token by an arbitrary sequence of characters
// conditional compilation
// macros with arguments

#define add(x, y) printf(#x  #y " adds to %d\n", x + y)
#define paste(x, y) x ## y
#define swap(t, x, y) {t temp = y; y = x; x = temp;}

int main() {
    int x, y;
    x = 3;
    y = 4;
    printf("BEFORE: \n");
    printf("%d\n", x);
    printf("%d\n", y);

    swap(int, x, y);
    printf("AFTER: \n");
    printf("%d\n", x);
    printf("%d\n", y);

    return 0;
}
