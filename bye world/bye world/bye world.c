#include<stdio.h>

int euclid(int a, int b)
{
	int num = 0;
	int  n = 0;
	n = a / b;

	num = a - b * n;

	printf("�ִ����� %d", num);
	return 0;
}


int main(void) {
	int a, b;
	printf("2���� ���� �Է� >>");
	scanf_s("%d %d", &a, &b);

	euclid(a, b);
	return 0;
}