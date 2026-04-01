#include <stdio.h>

int main() {
    float f;
    unsigned int i;

    printf("input: ");
    scanf_s("%f", &f);

    i = *(unsigned int*)&f;

    printf("%u/", (i >> 31) & 1);

    for (int k = 30; k >= 23; k--) {
        printf("%u", (i >> k) & 1);
        if (k == 27) {
            printf(" ");
        }
    }
    printf("/");

    for (int k = 22; k >= 0; k--) {
        printf("%u", (i >> k) & 1);
        if (k == 19 || k == 15 || k == 11 || k == 7 || k == 3) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}