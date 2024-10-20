#include <stdio.h>
#include <string.h>

#define MAXSIZE 1000

void reverse(char s[]) {
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

// integer to its string representation
void itoa(int n, char s[]) {
    int i, sign;
    if((sign = n) < 0) {
        n = -n;
    }

    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);

    if(sign < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}

void to_octal(int n, char s[]) {
    int i = 0;
    do {
        s[i++] = n % 8 + '0';
    } while((n /= 8) > 0);

    s[i] = '\0';
    reverse(s);
}

void to_hex(int n, char s[]) {
    int i = 0;

    do {
        if((n % 16) >= 10 && (n % 16) <= 15) {
            int mod = n % 16;
            switch(mod) {
                case 10: 
                         s[i++] = 'A';
                         printf("Does it get here?%d\n", i);
                         break;
                case 11: 
                         s[i++] = 'B';
                         break;
                case 12: 
                         s[i++] = 'C';
                         break;
                case 13: 
                         s[i++] = 'D';
                         break;
                case 14: 
                         s[i++] = 'E';
                         break;
                case 15: 
                         s[i++] = 'F';
                         break;
            }
            continue;
        }
        s[i++] = n % 16 + '0';
    } while((n /= 16) > 0);

    s[i] = '\0';
    reverse(s);
}

void to_binary(int n, char s[]) {
    int i = 0;
    do {
        s[i++] = n % 2 + '0';
    }while((n /= 2) > 0);

    s[i] = '\0';
    reverse(s);
}

void itob(int n, char s[], int base) {
    switch (base) {
        case 2:
            to_binary(n, s);
            break;
        case 8:
            to_octal(n, s);
            break;
        case 16:
            to_hex(n, s);
            break;
        default:
            printf("No such base\n");
    }
}

void itoa3(int n, char s[], int min_field_width) {
    int i, sign;
    if((sign = n) < 0) {
        n = -n;
    }

    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);

    if(sign < 0) {
        s[i++] = '-';
    }

    if(strlen(s) < min_field_width) {
        for(int idx = 0; idx < (min_field_width - strlen(s)); ++idx) {
            s[i++] = ' ';
        }
    }

    s[i] = '\0';
    reverse(s);
}

int main() {
    char s[MAXSIZE] = {};
    itoa3(-1, s, 3);
    printf("%s\n", s);

    return 0;
}
