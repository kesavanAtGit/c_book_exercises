#include <stdio.h>

int main() {
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;
    upper = 200;
    step = 20;

    // 0
    celsius = lower;

    printf("Celsius to fahrenheit table: \n");
    while(celsius <= upper) {
        // 9 /5 * (celsius + 32)
        fahr  = 9 * (celsius) / 5 + 32;
        printf("%2f\t%5.3f \n", celsius, fahr);
        celsius += step;
    }

    return 0;
}
