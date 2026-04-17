#include <stdio.h>
#include <time.h>
#include "GCD.h"

int main() {
	unsigned long long f1, f2, GCD;
	clock_t start_fib, end_fib, start_GCD, end_GCD;
	float current_time1, current_time2;

	printf(" n |      Fibonacci      | Fib Time |   GCD   |  GCD Time  |\n");
	printf("---|---------------------|----------|---------|------------|\n");
	for (int i = 5; i <= 93; i++) {

		start_fib = clock();
		f1 = Get_Fib(i - 1);
		f2 = Get_Fib(i);
		end_fib = clock();
		current_time1 = (float)(end_fib - start_fib) / CLOCKS_PER_SEC;

		start_GCD = clock();
		for (int j = 0; j <= 1000000; j++) {
			GCD = Get_GCD(f1, f2);
		}
		end_GCD = clock();
		current_time2 = (float)(end_GCD - start_GCD) / CLOCKS_PER_SEC;

		printf("%2.d |%20.llu | %.3fsec |    %llu    |  %.3fsec  | \n", i, f2, current_time1, GCD, current_time2 );
		

	}
	return 0;
}