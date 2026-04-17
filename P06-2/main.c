#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter the size of the magic square (odd number): ");
    scanf_s("%d", &n);

    if (n % 2 == 0) {
        fprintf(stderr, "ERROR: Only odd numbers are allowed.\n");
        return EXIT_FAILURE;
    }
	if (n <= 0) {
        fprintf(stderr, "ERROR: Please enter a positive integer greater than 0.\n");
        return EXIT_FAILURE;
    }

    // 동적 할당: int** 포인터 배열
    int** mabangin = (int**)malloc(n * sizeof(int*));

	if (mabangin == NULL) {
        fprintf(stderr, "ERROR: Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < n; i++) {
        *(mabangin + i) = (int*)malloc(n * sizeof(int));
        if (*(mabangin + i) == NULL) {
            fprintf(stderr, "ERROR: Memory allocation failed\n");
            for (int j = 0; j < i; j++) {
                free(*(mabangin + j));
            }
            free(mabangin);
            return EXIT_FAILURE;
        }
    }

    // 마방진 초기화
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            *(*(mabangin + i) + j) = 0;
        }
    }

    int num = 1;
    int row = 0, col = n / 2;

    while (num <= n * n) {
        *(*(mabangin + row) + col) = num++;

        int next_row = (row - 1 + n) % n;
        int next_col = (col + 1) % n;

        if (*(*(mabangin + next_row) + next_col) != 0) {
            row = (row + 1) % n;
        }
        else {
            row = next_row;
            col = next_col;
        }
    }

    // 배열 출력
    printf("Magic Square Array:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d", *(*(mabangin + i) + j));
        }
        printf("\n");
    }

    printf("Sum of Rows/Columns/Diagonals:\n");
    printf("\n");

    // 가로 합
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += *(*(mabangin + i) + j);
        }
        printf("Row %d: %d\n", i + 1, sum);
    }

    printf("\n");

    // 세로 합
    for (int j = 0; j < n; j++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += *(*(mabangin + i) + j);
        }
        printf("Column %d: %d\n", j + 1, sum);
    }

    printf("\n");

    // 대각선 합
    int diag1 = 0, diag2 = 0;
    for (int i = 0; i < n; i++) {
        diag1 += *(*(mabangin + i) + i);
        diag2 += *(*(mabangin + i) + (n - 1 - i));
    }
    printf("Downward diagonal sum : %d\n", diag1);
    printf("Upward diagonal sum : %d\n", diag2);

    // 메모리 해제
    for (int i = 0; i < n; i++)
        free(*(mabangin + i));
    free(mabangin);

    return 0;

}