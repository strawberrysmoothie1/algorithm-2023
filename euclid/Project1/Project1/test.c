#include<stdio.h>
#include<time.h>
#include"euclid.h"
#include"rand.h"


int testEuclid()
{
	int random_a[1000] = { 0 }; //1000개의 랜덤 정수 a
	int random_b[1000] = { 0 }; //1000개의 랜덤 정수 b
	int gcd[1000] = { 0 };      // a,b의 최대 공약수를 받음
	make_random(random_a, random_b);

	for (int i = 0; i < 1000; i++) {
		//gcd[i] = euclideRecursive(random_a[i], random_b[i]);  //재귀문
		gcd[i] = euclideRepeatitive(random_a[i], random_b[i]);  //반복문
		printf("(%d, %d)의 최대 공약수는: %d\n", random_a[i], random_b[i], gcd[i]);
	}

	return 0;
}