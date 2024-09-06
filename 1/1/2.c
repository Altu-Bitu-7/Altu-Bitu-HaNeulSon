#define _CRT_SECURE_NO_WARNINGS
#define N 10
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	int freq[6] = { 0 };

	srand(time(NULL));

	for (int i = 0; i < 10000; i++)
		++freq[rand() % 6];
	printf("숫자        횟수\n");
	
	for (int i = 0; i < 6; i++)
		printf("%d        %d\n", i + 1, freq[i]);
}