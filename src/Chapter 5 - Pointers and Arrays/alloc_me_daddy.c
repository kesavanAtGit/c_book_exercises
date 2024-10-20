#include <stdio.h>

#define ALLOCSIZE 10

static char allocbuf[ALLOCSIZE];
static char* allocp = allocbuf;

// [1, 1, 0, 0, 0] an int array of size 5
char* alloc(int n) {
    if((allocbuf + ALLOCSIZE - allocp) >= n) {
        allocp += n;
        return allocp - n;
    }else {
        fprintf(stderr, "Not enough storage, buy more RAM\n");
        return 0;
    }
}

void afree(char* p) {
    // [, , ,]
    if(p >= allocbuf && p < (allocbuf + ALLOCSIZE)) {
        allocp = p;
    }
}

int main() {
    // NOTES
    // Equality operators can be used with pointers of the elements of the same array
    // undefined behaviour if not pointers of the elements of the same array
    char* arr = alloc(3);
    printf("%s\n", arr);

    char* arr1 = alloc(3);
    printf("%s\n", arr);

    char* arr2 = alloc(3);
    printf("%s\n", arr);

    char* arr3 = alloc(3);
    printf("%s\n", arr);
    return 0;
}
