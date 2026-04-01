#include <stdio.h>

int main() {
    char talk[50] = "";

    printf("input: ");
    gets(talk);

    for (int i = 0; talk[i] != '\0'; i++) {
        if (talk[i] >= 'A' && talk[i] <= 'Z') {
            talk[i] = talk[i] + 32;
        }
        else if (talk[i] >= 'a' && talk[i] <= 'z') {
            talk[i] = talk[i] - 32;
        }
    }

    printf("output: %s\n", talk);

    return 0;
}