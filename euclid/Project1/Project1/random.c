// Euclid.cpp
#include<stdio.h>
#include<time.h>
// 1000개의 랜덤 값 a, b 정의
void make_random(int a[], int b[]) {
	int random_test = 0;

	for (int i = 0; i < 1000; i++) {
		a[i] = rand() % 1000 + 1;
		b[i] = rand() % 1000 + 1;
		if (b[i] >a[i]) {
			random_test = b[i];
			b[i] = a[i];
			a[i] = random_test;
		}
	}
}