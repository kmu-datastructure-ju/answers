#include <stdio.h>
#include <stdlib.h>

#include "GCD.h"

Function Get_GCD(Function num1, Function num2) {
	if (num2 == 0) return num1;
	return Get_GCD(num2, num1 % num2);
}

unsigned long long Get_Fib(int fib) {
	if (fib <= 1) return fib;
	return Get_Fib(fib - 1) + Get_Fib(fib - 2);
}