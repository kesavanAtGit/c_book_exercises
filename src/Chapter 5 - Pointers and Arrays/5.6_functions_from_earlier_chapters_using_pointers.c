#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXLEN 4 

static int n = 0;
int aToi(char* str) {
    while(isdigit(*str)) {
        n = n * 10 + (*str - '0');
        ++str;
    }

    return n;
}

void iToa(int n, char* s) {
    if(n / 10) {
        // iToa(10, 0)
        // iToa(1, 1)
        // s++ send the pos for the next char to be stored to the recursive call don't forget this again you dumbass
        iToa(n / 10, s++);
                // [, ->]
    }

    *s++ = (n % 10) + '0';
    *s= '\0';
}

int getLine(char s[], int max_len) {
    int c;
    char* ptr = s;

    for(s; s < (s + MAXLEN) && (c = getchar()) != EOF && c != '\n'; ++s) {
        *s = c;
    }

    // van\n\0
    if(c == '\n') { 
        *s++ = c;
    }

    *s = '\0';
    /*
       if(*s == '\0') {
           printf("CHAR?:%d\n", *s);
       }
    */
    return s - ptr;
}

int strindex(char* s, char* t) {
    int s_len = strlen(s) - 1;
    int t_len = strlen(t) - 1;

    char* i_ptr;
    char* j_ptr;
    char* k_ptr;
    char* ptr;

    for(i_ptr = s + s_len; i_ptr != s - 1; --i_ptr) {
        ptr = i_ptr;
        for(j_ptr = i_ptr, k_ptr = t + t_len; *j_ptr == *k_ptr && k_ptr != t - 1; --j_ptr, --k_ptr) {
            --ptr;
        }

        // meowfvanmew, van
        // meowfvanmew, van
        //      -
        if(k_ptr == t - 1) {
            printf("%c\n", *++ptr);
            return ptr - s;
        }else {
            ptr = s;
        }
    }
    return -1;
}

int main() {
    char s[MAXLEN];

    /*
       char* n = "23";
       printf("%d\n", aToi(n));

       int num = 24;
       iToa(num, s);
       printf("ARR: %s\n", s);
    */

    printf("%d\n", getLine(s, MAXLEN));
    /*
       while(getLine(s, MAXLEN) > 0) { 
       printf("%d\n", strindex(s, "van"));
       }
   */

    return 0;
}
