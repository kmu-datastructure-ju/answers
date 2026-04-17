#include <stdio.h>

#include "GCD.h"

int main() {
	Function num1, num2, GCD;
	while (1) {
		printf("Enter two integers to calculate their GCD: ");
		scanf_s("%d %d", &num1, &num2);
		if (num1 == 0 || num2 == 0) { printf("ERROR: Invalid input\n");  continue; }
		if (num1 < 0 || num2 < 0) { printf("Converting negative numbers to positive...\n"); num1 = abs(num1); num2 = abs(num2); }
		break;
	}
	GCD = Get_GCD(num1, num2);

	printf("GCD: %d", GCD);

	return 0;
}