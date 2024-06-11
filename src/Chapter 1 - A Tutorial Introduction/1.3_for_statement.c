#include <stdio.h>

// This is the exercise part
int main() {

    int fahr;

    printf("Fahrenheit to celsius: \n");
    for(fahr = 300; fahr >= 0; fahr -= 20) {
        printf("%d\t%3.3f \n", fahr, 5.0 / 9.0 * (fahr - 32));
    }

    return 0;
}
