#include <stdio.h>
#include <stdint.h>   

int main() {
    int8_t val = -1;
    
    // val의 메모리 주소를 unsigned char 포인터로 변환하는 과정입니다.
    // 메모리에 저장된 실제 1바이트 값을 확인하기 위해 사용합니다.
    unsigned char* ptr = (unsigned char*)&val;

    // 데이터가 저장된 메모리의 주소값을 저장하는 변수인 포인트, 즉 *ptr를 이용해 값이 0xFF이면 2의 보수 방식이라고 화면에 나옵니다.
    if (*ptr == 0xFF) {
        printf("Result: 2's complement\n");
    }
    // 위 코드와 동일하게 *ptr를 이용해 값이 0xFE이면 1의 보수 방식이라고 화면에 나옵니다.
    else if (*ptr == 0xFE) {
        printf("Result: 1's complement\n");
    }

    return 0;
}