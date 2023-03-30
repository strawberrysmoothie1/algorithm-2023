#include <stdio.h>

int main(void)
{
	int coin[4];     // 거스름돈 동전 개수 저장
	int change2[3];  // 거스르돈에서 나누고 남은돈 저장
	int change;      // 거스름돈 저장

	printf("거스름돈을 입력하세요");
	scanf_s("%d", &change);         //거스름돈 저장

	coin[0] = change / 500;         //500원개수 저장
	change2[0] = change % 500;      //거스름돈에서 500으로 나눈나머지 저장

	coin[1] = change2[0] / 100;     //100원개수 저장
	change2[1] = change2[0] % 100;  //거스름돈에서 100으로 나눈나머지 저장

	coin[2] = change2[1] / 50;      //50원개수 저장
	change2[2] = change2[1] % 50;   //거스름돈에서 50으로 나눈나머지 저장

	coin[3] = change2[2] / 10;      //10원개수 저장

	printf("거스름돈\n500원: %d개\n100원: %d개\n50원: %d개\n10원: %d개", coin[0], coin[1], coin[2], coin[3]); //거스름돈 동전 별로 개수 출력

}