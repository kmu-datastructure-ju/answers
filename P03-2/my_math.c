#include <stdio.h>
#include <stdlib.h>

#include "my_math.h"

Function Get_GCD(Function num1, Function num2) {
	int remain;
	while (num2 != 0) {
		remain = num1 % num2;
		num1 = num2;
		num2 = remain;
	}
	return num1;
}

Function Get_LCM(Function num1, Function num2) {
	Function GCD = Get_GCD(num1, num2);
	Function LCM = (num1 * num2) / GCD;
	return LCM;
}