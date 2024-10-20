#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXCHAR 1024

void copyChars(char start, char end, char dest[]) {
    size_t i;
    char ch = start;

    for(i = strlen(dest); ch <= end; ++i) {
        dest[i] = ch;
        ++ch;
    }
}

void copyDigits(char start, char end, char dest[]) {
    size_t i;
    for(i = strlen(dest); start <= end; ++i) {
        dest[i] = start;
        ++start;
    }
}

void expand(char str1[], char str2[]) {
    // this is the literal explanation for bad code, I guess :(
    int i;
    char startChar, endChar;
    int startDigit, endDigit;

    startChar = endChar = 0;
    startDigit = endDigit = 0;

    for(i = 0; i < strlen(str1); ++i) {
        if(str1[i] == '-' && i == 0) {
            str2[i] = str1[i];
            continue;
        }

        if(i == 0 && isalpha(str1[i])) {
            startChar = str1[i];
            continue;
        }else if(i == 0 && isdigit(str1[i])) {
            startDigit = str1[i];
            continue;
        }

        // gets the end char or digit
        if(str1[i] == '-' && isalpha(str1[i + 1])) {
            ++i;
            endChar = str1[i];
            
            for(int j = i + 1; j < strlen(str1); ++j) {
                if(str1[j] == '-' && isalpha(str1[j + 1])) {
                    ++j;
                    endChar = str1[j];
                    i = j;
                }else {
                    break;
                }
            }

            if(startChar && endChar) {
                copyChars(startChar, endChar, str2);
                startChar = endChar = 0;
                continue;
            }
        }else if(str1[i] == '-' && isdigit(str1[i + 1])) {
            ++i;
            endDigit = str1[i];
            if(startDigit >= '0' && endDigit <= '9') {
                copyDigits(startDigit, endDigit, str2);
                startDigit = endDigit = 0;
                continue;
            }
        }

        // handles the - before in the middle of the string and set the startChar and the startDigit
        if(isdigit(str1[i]) && (isdigit(str1[i - 1]) || isalpha(str1[i - 1]) || str1[i - 1] == '-')) {
            if(i > 1 && str1[i - 1] == '-') {
                str2[strlen(str2)] = '-';
            }
            startDigit = str1[i];
        }else if(isalpha(str1[i]) && (isalpha(str1[i - 1]) || isdigit(str1[i - 1]) || str1[i - 1] == '-')) {
            if(i > 1 && str1[i - 1] == '-') {
                str2[strlen(str2)] = '-';
            }
            startChar = str1[i];
        }
    }

    size_t len = strlen(str2);
    if(str1[i - 1] == '-') {
        str2[len++] = '-';
    }
    str2[len] = '\0';
}

int main() {
    char s[] = "-a-b-c-da-z-0-3-1-9-";
    char t[MAXCHAR] = {};

    expand(s, t);

    printf("%s\n", t);
    return 0;
}
