/*
- 숫자 N을 입력받아 동적 할당으로 크기가 N인 학생 구조체 배열을 생성한다.
- 학생 구조체 배열에는 이름(문자열), 학번(1~N), 성적(1~100) 필드가 존재한다.
- 학생의 이름은 아래 참고 학생 이름에서 무작위로 사용, 학번은 순서대로 증가, 성적은 무작위 범위 내 숫자를 사용하여 학생 배열을 생성한다.
- 이름 리스트는 파일 입출력으로 받아온다.
- 최저점 학생의 정보, 최고점 학생의 정보, 평균 점수를 출력한다.
- 이때 모든 배열 접근 연산은 포인터 연산자(*(arr + idx))를 통해 진행한다.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "stu.h"


int main()
{
	srand(time(NULL));

	int min, max;
	float av;

	int n;
	printf("Enter number of students(less than 100): ");
	scanf("%d", &n);
	printf("\n");

	if (n <= 0 || n > 100)
	{
		printf("ERROR");
		return 1;
	}

	Student* arr = malloc(sizeof(Student) * n);

	if (arr == NULL)
	{
		printf("Memory allocation failed\n");
		return 1;
	}

	rFile(n, arr);
	wStuNum(n, arr);
	wScore(n, arr);

	min = mini(n, arr);
	max = maxi(n, arr);
	av = ave(n, arr);

	printf("The Lowest Stu Infomation\nName: %s\nStudent Number: %d\nScore: %d\n", (arr + min)->name, (arr + min)->stuNum, (arr + min)->score);
	printf("\n");
	printf("The Highest Stu Infomation\nName: %s\nStudent Number: %d\nScore: %d\n", (arr + max)->name, (arr + max)->stuNum, (arr + max)->score);
	printf("\n");
	printf("Average: %.2f\n", av);

	return 0;
}