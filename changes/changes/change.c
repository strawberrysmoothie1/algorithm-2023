#include <stdio.h>

int main(void)
{
	int coin[4];
	int change2[3];
	int change;

	printf("거스름돈을 입력하세요");
	scanf_s("%d", &change);

	coin[0] = change / 500;
	change2[0] = change % 500;

	coin[1] = change2[0] / 100;
	change2[1] = change2[0] % 100;

	coin[2] = change2[1] / 50;
	change2[2] = change2[1] % 50;

	coin[3] = change2[2] / 10;
	
	printf("거스름돈\n500원: %d개\n100원: %d개\n50원: %d개\n10원: %d개", coin[0], coin[1], coin[2], coin[3]);

}