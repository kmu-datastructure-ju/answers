# • 최대공약수(GCD)와 최소공배수(LCM) •

이 프로그램은 두 정수를 입력받아 최대공약수(GCD)와 최소공배수(LCM)를 산출합니다.


## 1. 최대공약수(GCD) - 유클리드 호제법
두 수 $a, b$ (단, $a > b$)에 대하여 $a$를 $b$로 나눈 나머지를 $r$이라 할 때, $GCD(a, b) = GCD(b, r)$임을 이용합니다.

**[Pseudo Code]**
```text
FUNCTION Get_GCD(a, b)
    WHILE b가 0이 아닐 동안 반복:
        r = a % b (a를 b로 나눈 나머지)
        a = b
        b = r
    RETURN a (최종적으로 남은 a가 GCD)
ENDFUNCTION
```

## 2. 최소공배수(LCM) - 관계식 활용
두 수 $a, b$의 곱은 두 수의 최대공약수(GCD)와 최소공배수(LCM)의 곱과 같다는 원리를 이용합니다.

$a \times b = GCD \times LCM$  =>  $LCM = (a \times b) / GCD$

**[Pseudo Code]**

```text
FUNCTION Get_LCM(a, b, gcd)
    LCM = (a * b) / gcd
    RETURN LCM
ENDFUNCTION
```
