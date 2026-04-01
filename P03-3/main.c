#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../P03-1/my_fraction.h"

int main(int c, char** v) {
	Fraction f1, f2, muiti2 = { 2, 1 };
	if (c != 3) {
		printf("Enter: %s <Width> <Height>", v[0]);
		return 1;
	}

	f1 = Create(v[1]);
	f2 = Create(v[2]);

	if (f1.num <= 0 || f2.num <= 0) {
		printf("ERROR: Zero and negative numbers are not allowed\n");
		return 1;
	}

	Fraction Perimeter = Add(f1, f2);
	Perimeter = Multiply(Perimeter, muiti2);

	Fraction Area = Multiply(f1, f2);
	printf("Perimeter: ");
	Print(Perimeter);
	printf("Area: ");
	Print(Area);
	printf("\n");
	return 0;
}