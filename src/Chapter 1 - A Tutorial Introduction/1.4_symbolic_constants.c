#include <stdio.h>

#define LOWER 0
#define HIGHER 300
#define STEP 20

int main() {
    int fahr;

    printf("Fahrenheit to celsius: \n");
    for(fahr = HIGHER; fahr >= LOWER; fahr -= STEP) {
        printf("%d\t%3.3f \n", fahr, 5.0/9.0 * (fahr - 32));
    }

    return 0;
}
