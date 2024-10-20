#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/*
   Equality operators can be used with pointers of the elements of the same array
   undefined behaviour if not pointers of the elements of the same array
   Assignment of pointer of the same type
   Adding or subtracting pointers with integers
   Comparing pointers of the elements of the same array and with zero
   Subtrating with same array pointers and all that shit
*/

/*
 *  TODO: don't even know what the below line means anymore
    TODO: Char pointers and functions
*/

int strLen(char* s) {
    char* p = s;
    // using ptrdiff_t to store the difference of the two pointers since an int may not suffice
    ptrdiff_t diff;

    while(*p != '\0'){ 
        ++p;
    }

    diff = p - s;
    return diff;
}

void strCpy(char* s, char* p) {
    while((*s++ = *p++) != '\0')  {
    }
}

int main() {
    char *arr = malloc(sizeof(char) * 10);
    strCpy(arr, "hello");

    printf("%s\n", arr);

    for(int i = 0; i < strlen(arr); ++i) {
        if(arr[i] == '\0') {
            printf("Null terminator found \n");
        }
    }
    return 0;
}
