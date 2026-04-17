#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf_s("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive integer greater than 0.\n");
        return 1;
    }

    // 동적 할당
    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("ERROR: Memory allocation failed\n");
        return 1;
    }

    srand(time(NULL));

    // 0~N 사이의 난수로 배열 채우기
    int* ptr = arr;
    for (int i = 0; i < n; i++) {
        *(ptr + i) = rand() % (n + 1); // 0~N 범위의 난수
    }

    // 순방향 출력
    printf("--- Print Forward ---\n");
    for (int i = 0; i < n; i++) {
        printf("%d: %d\n", i + 1, *(ptr + i));
    }

    // 역방향 출력
    printf("--- Print Backward ---\n");
    for (int i = n - 1; i >= 0; i--) {
        printf("%d: %d\n", i + 1, *(ptr + i));
    }

    // 총합, 최대값, 최소값
    int sum = 0;
    int max = *ptr;
    int max_idx = 0;
    int min = *ptr;
    int min_idx = 0;

    for (int i = 0; i < n; i++) {
        int val = *(ptr + i);
        sum += val;
        if (val > max) { max = val; max_idx = i; }
        if (val < min) { min = val; min_idx = i; }
    }

    printf("------------------------------------------------------------------\n");
    printf("Total Sum: %d\n", sum);
    printf("Maximum Value: %d (Position: %d)\n", max, max_idx + 1);
    printf("Minimum Value: %d (Position: %d)\n", min, min_idx + 1);

    free(arr);
    return 0;
}