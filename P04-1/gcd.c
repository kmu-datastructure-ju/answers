#include <stdio.h>
#include <stdlib.h>

#include "GCD.h"

Function Get_GCD(Function num1, Function num2) {
	int remain;
	while (num2 != 0) {
		remain = num1 % num2;
		num1 = num2;
		num2 = remain;
	}
	return num1;
}