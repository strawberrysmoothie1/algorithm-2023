#include<stdio.h>


// 재귀적 최대공약수
int euclideRecursive(int a, int b)
{
	if (b == 0) {
		return a;
	}

	return euclideRecursive(b, a % b);
}

// 반복적 최대공약수
int euclideRepeatitive(int a, int b)
{
	int c = 0;
	while (b!=0) 
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}