#include<stdio.h>
#include<time.h>



int main()
{
	clock_t start, finish; //시간 구하기
	double duration;
	start = clock();
	int ret;
	ret = testEuclid();
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("%f 초입니다.\n", duration);
	return 0;
}