# 2) 피보나치 수열의 시 복잡도 분석 및 프로파일링

## 1. 알고리즘 구현 코드
GCD.h: https://github.com/Hajihwan-04/5820277_DataStructure1/blob/master/Assignment/2026.03.26/Fibonacci_Profiling/GCD.h

GCD.c: https://github.com/Hajihwan-04/5820277_DataStructure1/blob/master/Assignment/2026.03.26/Fibonacci_Profiling/GCD.c

main.c: https://github.com/Hajihwan-04/5820277_DataStructure1/blob/master/Assignment/2026.03.26/Fibonacci_Profiling/main.c

피보나치 수열 생성 및 유클리드 호제법을 수행하기 위해 작성된 C 언어 코드는 다음과 같다.
피보나치 수열 생성을 하는 $Get Fib$ 함수는 $n$번째인 피보나치 수를 찾는 가능한 많은 연산을 거치는 방식 중 하나이고, 유클리드 호제법을 이용한 $Get GCD$ 함수를 1,000,000번 반복하는 것은 걸리는 시간이 너무 짧아 시각화 하기 위함이다. 

```c
GCD.h

typedef unsigned long long Function;

//최대공약수를 구함
extern Function Get_GCD(Function num1, Function num2);
//피보나치 수열
extern unsigned long long Get_Fib(int fib);
```
```c
GCD.c

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
```

```c
main.c

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

		printf("%2.d |%20.llu |  %.3f초 |    %llu    |   %.3f초  | \n", i, f2, current_time1, GCD, current_time2 );
		

	}
	return 0;
}
```

## 2. 프로파일링 결과
$n$을 5부터 증가시키며 측정한 연산 시간 및 메모리 사용량의 추이는 다음과 같다.

(n이 93일때 까지 동작시키는데 무리가 있어 51번째까지 나온 결과값으로 이후의 각 피보나치 값을 구하는 시간은 예측하였다. GCD함수를 동작하는 시간은 따로 측정하여 모두 측정한 값이다.)
### CPU 사용량 분석 및 메모리 사용량 분석
<img width="1278" height="659" alt="프로파일링 자료" src="https://github.com/user-attachments/assets/b67e46dd-d52e-4947-8d1b-722b4da04e94" />
<img width="1280" height="656" alt="CPU 사용량" src="https://github.com/user-attachments/assets/02201447-1930-47ba-8ef4-4edb55245d44" />

### 2.1 GCD의 시간 복잡도 검증

#### • GCD 연산 시간 복잡도의 수학적 증명 (라메의 정리)
유클리드 호제법의 일반적인 시간 복잡도는 입력되는 두 수 중 작은 수를 $b$라고 할 때 $O(\log b)$이다. 즉, 입력값의 비트 수(자릿수)에 비례하여 연산 시간이 늘어난다.

본 과제에서는 피보나치 수열의 연속된 두 항 $F(n)$과 $F(n-1)$을 입력값으로 사용한다. 라메의 정리(Lamé's Theorem)에 따르면, 연속된 피보나치 수를 입력하는 것은 유클리드 호제법에서 가장 많은 나눗셈 연산을 발생시키는 최악의 경우(Worst Case)이다.

본 증명의 목표는 입력값 자체의 크기($F(n)$)가 아닌, **피보나치 수열의 인덱스 $n$을 기준으로 보았을 때 순수 GCD 연산의 시간 복잡도가 어떤 형태를 띠는지 수학적으로 도출**하는 것이다.

#### • 수학적 유도 과정
입력값의 크기($F(n)$)와 인덱스($n$) 사이의 수학적 연결 고리를 만들기 위해 피보나치 수열의 일반항 근사식을 이용한다.

1. **피보나치 수열의 일반항 근사식:**
   피보나치 수열은 $n$이 증가함에 따라 기하급수적으로 증가하며, 비네의 공식에 의해 다음과 같이 근사할 수 있다.
   $$F(n) \approx \frac{\phi^n}{\sqrt{5}}$$ 
   (단, $\phi$는 황금비 $\frac{1 + \sqrt{5}}{2} \approx 1.618$)

2. **이론적 시간 복잡도에 입력값 대입:**
   입력값 중 작은 수인 $b = F(n-1)$을 유클리드 호제법의 이론적 시간 복잡도 수식에 대입한다.
   $$T(n) = O(\log(F(n-1)))$$

3. **근사식 대입 및 로그 식 전개:**
   입력값 $F(n-1)$ 자리에 피보나치 근사식을 대입한다.
   $$T(n) = O\left(\log\left(\frac{\phi^{n-1}}{\sqrt{5}}\right)\right)$$
   로그의 성질($\log(a/b) = \log a - \log b$, $\log(a^b) = b\log a$)을 이용하여 위 식을 전개하면 다음과 같다.
   $$T(n) = O((n-1)\log\phi - \log\sqrt{5})$$

4. **빅오(Big-O) 표기법 적용:**
   빅오 표기법에서는 $n$에 무관한 상수항 ($-\log\sqrt{5}$, $-\log\phi$)과 상수의 곱 ($\log\phi$)은 무시하고 가장 높은 차수의 항만 남긴다.
   $$T(n) = O(n)$$

#### • 증명 결론
수학적 유도 결과, 입력값 자체의 크기에 대해서는 로그 $O(\log b)$ 복잡도를 가지지만, 연속된 피보나치 수의 **인덱스 $n$을 기준으로 보았을 때 순수 GCD 연산 단계는 선형 시간 복잡도인 $O(n)$** 으로 증가함을 알 수 있다.

<img width="533" height="319" alt="GCD_TIME" src="https://github.com/user-attachments/assets/bfd52de4-ab56-4f57-a681-b6d9b9468eda" />

### 2.2 피보나치 수열 생성 함수의 시간 복잡도 분석

#### 2.2.1 재귀 함수의 구조
본 과제에서 피보나치 수열의 $n$번째 항을 구하기 위해 사용된 함수는 다음과 같이 자기 자신을 두 번씩 호출하는 재귀(Recursion) 형태로 구현되어 있다.

```c
unsigned long long Get_Fib(int fib) {
    if (fib <= 1) return fib;
    return Get_Fib(fib - 1) + Get_Fib(fib - 2);
}
```

#### 2.2.2 시간 복잡도 점화식 및 수학적 증명
입력값 $n$에 대한 함수의 연산 시간(호출 횟수)을 $T(n)$이라고 정의하면, 내부 연산 흐름에 따라 다음과 같은 점화식을 도출할 수 있다.

$$T(n) = T(n-1) + T(n-2) + O(1)$$

이 점화식을 실행 흐름에 따라 트리 구조로 펼쳐보면, 하나의 함수가 실행될 때마다 두 개의 함수로 가지를 치며 뻗어나가는 이진 트리(Binary Tree) 형태가 된다. 트리의 깊이가 1단계 깊어질 때마다 호출되는 함수의 개수는 최대 2배씩 증가하며, 이를 바탕으로 Big-O 표기법을 유도하면 다음과 같다.

1. **상한선(Upper Bound) 추정:**
   $T(n-1)$과 $T(n-2)$ 중 더 큰 값인 $T(n-1)$로 식을 단순화하여 최악의 상한선을 구해보면 다음과 같다.
   $$T(n) \le 2T(n-1) + O(1)$$
   이를 계속 전개하면 최종적으로 **지수 시간 복잡도인 $O(2^n)$** 이 도출된다.

2. **엄밀한 시간 복잡도 (Tight Bound):**
   함수 호출 횟수 $T(n)$ 자체도 피보나치 수열의 증가 속도를 따르므로, 비네의 공식을 적용하여 황금비 $\phi$($\approx 1.618$)를 이용해 표현하면 더욱 엄밀한 복잡도인 **$O(1.618^n)$** 을 얻을 수 있다.

#### 2.2.3 연산 시간 및 값의 실증적 검증 (프로파일링)
앞서 증명한 이론적 지수 시간 복잡도가 실제 환경에서 어떻게 나타나는지 프로파일링 데이터를 통해 검증한다.

#### 2.2.4 피보나치 수의 기하급수적 성장
<img width="459" height="275" alt="Fibonacci" src="https://github.com/user-attachments/assets/7f0956c9-ba7c-48f9-a0cb-bb87eff94c6e" />

위 그래프는 인덱스 $n$에 따른 피보나치 수 $F(n)$의 실제 값 변화를 보여준다. $n$이 증가함에 따라 값이 폭발적으로 증가하는 명확한 지수 함수 형태를 띠며, 이는 이론적인 $O(\phi^n)$ 복잡도를 실증한다.

#### 2.2.5 피보나치 함수의 실행 시간 분석
<img width="461" height="274" alt="Fibonacci_Time" src="https://github.com/user-attachments/assets/1079438c-495e-4331-b82e-9bc508eac6d4" />

위 그래프는 재귀 방식으로 구현된 `Get_Fib` 함수의 순수 실행 시간을 측정한 결과이다. $n$이 약 70을 넘어가는 시점부터 연산 시간이 급격하게 수직 상승하며 명확한 지수 함수 $O(2^n)$ 형태를 그리는 것을 확인할 수 있다.

## 3 결론
수학적 증명 결과, 엄밀한 시간 복잡도는 $O(1.618^n)$이지만, 컴퓨터 공학의 Big-O 표기법에서는 통상적으로 대수적 상한선인 **지수 시간 복잡도 $O(2^n)$** 으로 표기한다. 

이는 인덱스 $n$이 증가함에 따라 연산량이 기하급수적으로 폭발하여 실행 시간이 기하급수적으로 늘어남을 의미한다. 이러한 재귀적 특성 때문에, 앞선 최대공약수(GCD) 프로파일링 과정에서 피보나치 항을 구하는 시간이 전체 실행 시간의 병목(Bottleneck) 현상을 유발하는 주요 원인이 된다.
