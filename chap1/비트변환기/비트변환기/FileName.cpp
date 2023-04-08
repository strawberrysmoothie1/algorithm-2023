#include<stdio.h>

int main() {

	double a = 0,  d = 0;
	int n = 0, i, b=0, c;
	printf("숫자입력");
	scanf_s("%lf", &a);

	n = a / 3;

	for (i = 0; i < n; i++) {
		b %= 3;

		printf("%d ", b);
	}


	return 0;
}
