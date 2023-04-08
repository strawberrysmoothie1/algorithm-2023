#include<stdio.h>
#include<time.h>
#include"euclid.h"
#include"rand.h"


int testEuclid()
{
	int random_a[1000] = { 0 }; //1000���� ���� ���� a
	int random_b[1000] = { 0 }; //1000���� ���� ���� b
	int gcd[1000] = { 0 };      // a,b�� �ִ� ������� ����
	make_random(random_a, random_b);

	for (int i = 0; i < 1000; i++) {
		//gcd[i] = euclideRecursive(random_a[i], random_b[i]);  //��͹�
		gcd[i] = euclideRepeatitive(random_a[i], random_b[i]);  //�ݺ���
		printf("(%d, %d)�� �ִ� �������: %d\n", random_a[i], random_b[i], gcd[i]);
	}

	return 0;
}