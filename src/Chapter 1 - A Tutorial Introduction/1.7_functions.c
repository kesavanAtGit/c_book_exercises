#include <stdio.h>

double fahrenheitToCelsius(double fahr) {
    double celsius = 0;

    celsius = 5 * (fahr - 32) / 9;
    return celsius;
}

// this is a function prototype
double power(double base, int n);

// Raise m to the power of n
double power(double base, int n) {
    double p;
    p = 1;

    for(int i = 0; i < n; ++i) {
        p = p * base;
    }
    return p;
}

int main() {
    // printf("%.3f\n", power(-2.3, 3));

    printf("%.3f\n", fahrenheitToCelsius(96));
    return 0;
}

