#include <stdio.h>

int main() {
    double input;
    printf("Enter number: ");
    scanf_s("%lf", &input);

    unsigned short bits = (unsigned short)(short)(input * 256);

    printf("Result: ");
    for (int i = 15; i >= 0; i--) {
        printf("%d", (bits >> i) & 1);

        if (i == 8) printf(".");
    }
    printf("\n");

    return 0;
}