#include <stdio.h>

#define LIMIT 10

int main() {
    // arithmetic operators: +, -, *, /, %
    // precedence is lower than *, /, % 
    // associativity: left to right

    // relational operators: >, <, >=, <=
    // equality operators: !=, ==
    // logical operators: ||, &&
    // negation operator: !

    int c, i;
    i = 0;

    char arr[LIMIT];

    while(i < (LIMIT - 1)) {
        if((c = getchar()) != EOF) {
            if(c == '\n') {
                arr[i] = c;
            }

            if(c == '\n') {
                arr[i++] = c;
                arr[i] = '\0';
                break;
            }
        }
        ++i;
    }

    printf("The len of the string is: %d\n", i);

    printf("The string read is: %s", arr);

    return 0;
}
