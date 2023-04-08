#include<stdio.h>


// ����� �ִ�����
int euclideRecursive(int a, int b)
{
	if (b == 0) {
		return a;
	}

	return euclideRecursive(b, a % b);
}

// �ݺ��� �ִ�����
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