#include<stdio.h>
#include<time.h>



int main()
{
	clock_t start, finish; //�ð� ���ϱ�
	double duration;
	start = clock();
	int ret;
	ret = testEuclid();
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("%f ���Դϴ�.\n", duration);
	return 0;
}