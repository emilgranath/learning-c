#include <stdio.h>
#include <stdlib.h>

int main(void) {
    double celsius = 0.0;

    printf("Enter temperature in Celsius: ");

    if (scanf("%lf", &celsius) != 1){
        fprintf(stderr, "Error: please enter a number.\n");
        return EXIT_FAILURE;
    }

    double fahrenheit = celsius * 9.0 / 5.0 + 32;

    printf("%.1f C = %.1f F\n", celsius, fahrenheit);
    return EXIT_SUCCESS;
}