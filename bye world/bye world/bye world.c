#include<stdio.h>

int euclid(int a, int b)
{
	int num = 0;
	int  n = 0;
	n = a / b;

	num = a - b * n;

	printf("최대공약수 %d", num);
	return 0;
}


int main(void) {
	int a, b;
	printf("2개의 정수 입력 >>");
	scanf_s("%d %d", &a, &b);

	euclid(a, b);
	return 0;
}