#include <stdio.h>

// fahr to celsius table

int main() {
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;
    upper = 200;
    step = 20;

    // 0
    fahr = lower;

    while(fahr <= upper) {
        celsius  = 5 * (fahr - 32) / 9;
        printf("%0.2f\t%0.2f \n", fahr, celsius);
        fahr = lower += step;
    }

    return 0;
}
