#include <stdio.h>

int strend(char* s, char* t) {
    char* ptr_t = t;
    while(*s) {
        while(*s == *t) {
            if(*s == '\0' && *t == '\0') {
                return 1;
            }
            ++s, ++t;
        }

        ++s; 
        t = ptr_t;
    }
    return 0;
}

int main() {
    char s[] = "is there something wrong with this this kesavan?";
    char t[] = "this that this kesavan?";

    printf("%d\n", strend(s, t));

    return 0;
}
