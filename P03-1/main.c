#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "my_fraction.h"

int main() {
	Fraction f1, f2, result;
	char s1[100], op, s2[100];
	printf("Calculator\n\n");

	while (1) {
		printf("e.g. [NUM] [OP] [NUM]\nCan enter [NUM] as fraction form([NUM]/[NUM])\nEnter: ");
		scanf_s("%s %c %s", s1, (unsigned)sizeof(s1), &op, 1, s2, (unsigned)sizeof(s2));
		f1 = Create(s1);
		if (f1.den == 0) continue;
		f2 = Create(s2);
		if (f2.den == 0) continue;

		int pass = 0;
		switch (op) {
		case '+':result = Add(f1, f2); break;
		case '-':result = Subtract(f1, f2); break;
		case '*':result = Multiply(f1, f2); break;
		case '/':result = Divide(f1, f2); { if (f2.num == 0) pass = 2; break; }
		default: printf("ERROR: Invalid operator '%c'\n", op); pass = 1;
		}
		if (pass == 0) break;
		if (pass == 2) continue;
	}
	printf("Result : ");
	Print(result);
	printf("\n");

	return 0;
}