#pragma once
typedef struct Fraction { int num; int den; } Fraction;

//입력받은 수를 분수, 소수, 정수 형태를 구분하고 분수형태의 하나의 자료형으로 변형
extern Fraction Create(char* str);
//두 수의 덧셈
extern Fraction Add(Fraction f1, Fraction f2);
//두 수의 뺄셈
extern Fraction Subtract(Fraction f1, Fraction f2);
//두 수의 곱셈
extern Fraction Multiply(Fraction f1, Fraction f2);
//두 수의 나눗셈
extern Fraction Divide(Fraction f1, Fraction f2);
//기약분수로 변형
extern Fraction Simplify(int num, int den);
//결과의 수를 출력함
extern void Print(Fraction f1);