#include <stdio.h>

int findFakecoin(int coin[], int coinadd[])
{
	if (coinadd[1] > coinadd[2]) {   //1. �� �׷����� ����1
		if (coinadd[3] > coinadd[4]) { //�ι�°�׷�1
			if (coin[1] > coin[2]) { 
				return coin[1];
			}
			else if (coin[2] > coin[1]) {
				return coin[2];
			}
		}
		else if (coinadd[4] > coinadd[3]) { //�ι�°�׷�1
			if (coin[3] > coin[4]) {
				return coin[3];
			}
			else if (coin[4] > coin[3]) {
				return coin[4];
			}
		}
		else if (coinadd[3] = coinadd[4]) { //�ι�° �׷��� ���Ӱ��� ��
			return coin[0];
		}
	}
	else if (coinadd[2] > coinadd[1]) { //1. �� �׷����� ����2
		if (coinadd[5] > coinadd[6]) {//�ι�°�׷�3
			if (coin[6] > coin[7]) {
				return coin[6];
			}
			else if (coin[7] > coin[6]) {
				return coin[7];
			}
		}
		else if (coinadd[6] > coinadd[5]) {//�ι�°�׷�4
			if (coin[8] > coin[9]) {
				return coin[8];
			}
			else if (coin[9] > coin[8]) {
				return coin[9];
			}
		}
		else if (coinadd[5] = coinadd[6]) {
			return coin[5];
		}
	}
}
int main(void)
{
	int coin[10];
	int coinadd[7];
	printf("10���� �����Է� (��¥������1 ��¥������0)");
	scanf_s("%d", &coin);

	int coinadd[1] = coin[0] + coin[1] + coin[2] + coin[3] + coin[4];
	int coinadd[3] = coin[1] + coin[2];
	int coinadd[4] = coin[3] + coin[4];
	int coinadd[2] = coin[5] + coin[6] + coin[7] + coin[8] + coin[9];
	int coinadd[5] = coin[6] + coin[7];
	int coinadd[6] = coin[8] + coin[9];

	int fakecoin = findFakecoin(coin, coinadd);

	printf("%d", fakecoin);
	return 0;
}