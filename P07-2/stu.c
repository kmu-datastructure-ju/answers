#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "stu.h"

void rFile(int n, Student* arr)
{
    FILE* fp;

    fp = fopen("name_list.txt", "r");

    if (fp == NULL)
    {
        printf("Fail to open\n");
        return;
    }
    else
    {
        int i = 0; // 읽은 이름 개수
        int length;
        int rd;
        char file_buff[50];

        int* used = malloc(sizeof(int) * n); // 0: 사용 가능, 1: 이미 사용

        if (used == NULL)
        {
            printf("Memory allocation failed\n");
            free(used);
            return;
        }

        for (int i = 0; i < n; i++)
            *(used + i) = 0;

        char* fileB = malloc(sizeof(char) * 50 * n);

        if (used == NULL || fileB == NULL)
        {
            printf("Memory allocation failed\n");
            free(used);
            free(fileB);
            return;
		}

        while (fgets(file_buff, sizeof(file_buff), fp) != NULL && i < n)
        {
            length = strlen(file_buff);
            if (length > 0 && *(file_buff + length - 1) == '\n')
                *(file_buff + length - 1) = '\0';

            strcpy(fileB + i * 50, file_buff);
            i++;
        }

        for (int j = 0; j < n; j++)
        {
            rd = rand() % i;

            while (*(used + rd) == 1)
            {
                rd = rand() % i;
            }

            strcpy(file_buff, fileB + rd * 50);
            strcpy((arr + j)->name, file_buff);
            *(used + rd) = 1;
        }

        fclose(fp);

        free(used);
        free(fileB);
    }
}

void wStuNum(int n, Student* arr)
{
    for (int i = 0; i < n; i++)
    {
        (arr + i)->stuNum = i + 1;
    }

    return;
}

void wScore(int n, Student* arr)
{
    for (int i = 0; i < n; i++)
    {
        (arr + i)->score = rand() % 100 + 1; // 1~100
    }

    return;
}

int maxi(int n, Student* arr)
{
    int max = arr->score;
    int num = 0;

    for (int i = 1; i < n; i++)
    {
        if (max < (arr + i)->score)
        {
            max = (arr + i)->score;
            num = i;
        }
    }

    return num;
}

int mini(int n, Student* arr)
{
    int min = arr->score;
    int num = 0;

    for (int i = 1; i < n; i++)
    {
        if (min > (arr + i)->score)
        {
            min = (arr + i)->score;
            num = i;
        }
    }

    return num;
}

float ave(int n, Student* arr)
{
    int sum = 0;
    float av;

    for (int i = 0; i < n; i++)
    {
        sum += (arr + i)->score;
    }

    av = (float)sum / n;

    return av;
}