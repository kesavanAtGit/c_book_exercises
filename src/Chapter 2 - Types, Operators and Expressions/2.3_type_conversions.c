#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

// Extra exercise for my satisfaction: octal to decimal
int otoi(const char* hex_str, int arr_len) {
    int i, n, temp;
    temp = n = 0;

    for(i = 0; i < arr_len; ++i) {
        // handle alphabets here
        if(isalpha(hex_str[i])) {
            printf("Not a valid octal digit. \n");
            return -1;
        }

        if(hex_str[i] == '0') {
            i += 1;
        }

        if(hex_str[i] >= '0' && hex_str[i] <= '7') {
            temp = hex_str[i] - '0';
        }else {
            printf("Not a valid octal digit. \n");
            return -1;
        }

        n += temp * (int)pow(8, arr_len - i - 1);
    }

    return n;
}

int htoi(const char* hex_str, int arr_len) {
    int i, n;
    n = 0;

    int temp;
    for(i = 0; i < arr_len; ++i) {
        if(hex_str[i] == '\\' && (hex_str[i + 1] == 'x' || hex_str[i + 1] == 'X')) {
            i += 2;
        }

        temp = tolower(hex_str[i]);

        if(isdigit(hex_str[i])) {
            temp -= '0';
        }

        if(isalpha(hex_str[i]) && hex_str[i] <= 'f') {
            temp = hex_str[i] - 'a' + 10;
        }

        // \x0A 10
        // 10 * 16 to the power of  1-0-1 so 10 * 1
        n += temp * (int)pow(16, arr_len - i - 1);
    }

    return n;
}

int main() {
    const char* hex_str = "\x0A";
    int arr_len;

    arr_len = strlen(hex_str);
    printf("%d\n", arr_len);

    printf("%d\n", htoi(hex_str, arr_len));
    return 0;
}
