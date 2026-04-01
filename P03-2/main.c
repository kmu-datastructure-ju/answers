#include <stdio.h>

#include "my_math.h"

int main() {
	Function num1, num2, GCD, LCM;
	while (1) {
		printf("Enter two integers to get GCD and LCM: ");
		scanf_s("%d %d", &num1, &num2);
		if (num1 == 0 || num2 == 0) { printf("ERROR: 0 cannot be entered\n");  continue; }
		if (num1 < 0 || num2 < 0) { printf("INFO: Calculate by converting a negative number to a positive number\n"); num1 = abs(num1); num2 = abs(num2); }
		GCD = Get_GCD(num1, num2);
		LCM = Get_LCM(num1, num2);
		break;
	}

	printf("GCD: %d, LCM: %d", GCD, LCM);

	return 0;
}