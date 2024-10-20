#include <stdio.h>

void strCat(char* dest, char* src) {
    /*
    int idx = 0;
    while(dest[idx]) {
        ++idx;
    }

    for(int i = 0; src[i] != '\0'; ++i) {
        dest[idx++] = src[i];
    }

    while((*(dest + idx) = *src++)) {
        ++idx;
    }
    */

    while(*dest) { 
        ++dest;
    }

    while((*dest++ = *src++)) {
    }
}

int main() {
    char dest[32] = "hello ";
    char src[] = "world";

    strCat(dest, src);
    puts(dest);

    return 0;
}
