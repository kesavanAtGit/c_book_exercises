#include <stdio.h>
#include <ctype.h>
#include <math.h>

double atof(char s[]) {
    double val, power, exponent;
    int sign, i;

    for(i = 0; isspace(s[i]); ++i) {
    }

    sign = (s[i] == '-')? -1: 1;

    for(val = 0.0; isdigit(s[i]); ++i) {
        val = 10.0 * val + (s[i] - '0');
    }

    if(s[i] == '.') ++i;
    for(power = 1.0; isdigit(s[i]); ++i) {
        val = 10.0 * val + (s[i] - '0');
        power*= 10.0;
    }

    if(s[i] == 'e' || s[i] == 'E') ++i;

    if(s[i] == '-') {
        ++i;
        exponent = 1 / pow(10, s[i] - '0');
    }else if(s[i] == '+') {
        ++i;
        exponent = pow(10, s[i] - '0');
    }else {
        exponent = pow(10, s[i] - '0');
    }

    return sign * (val / power) * exponent;

}

int main() {
    printf("%g\n", atof("1.23E+2"));
    return 0;
}
