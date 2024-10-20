#include <stdio.h>

void strnCpy(char* s, char* t, int n);
char* strnCat(char* s, char* t, int n);
int strnCmp(char* s, char* t, int n);

int main() {
    char dest[32] = "str";
    char* src = "awang";

    return 0;
}

void strnCpy(char* s, char* t, int n) { 
    char* ptr_t = t;

    while((*s++ = *t++)) {
        if(t == ptr_t + n) {
            return;
        }
    }
}

char* strnCat(char* s, char* t, int n) {
    char* ptr_t = t;

    while(*s) {
        ++s;
    }

    while(t != (ptr_t + n) && (*s++ = *t++)) {
    }
    return s;
}

int strnCmp(char* s, char* t, int n) { 
    char* ptr_t = t;

    if(*t == '\0') {
        printf("Empty string???\n");
        return 0;
    }

    while(t != (ptr_t + n) && *t == *s) {
        ++s, ++t;
    }
    
    return *t - *s;
}
