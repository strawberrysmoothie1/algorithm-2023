#include <stdio.h>

int main(void)
{
	int coin[4];
	int change2[3];
	int change;

	printf("�Ž������� �Է��ϼ���");
	scanf_s("%d", &change);

	coin[0] = change / 500;
	change2[0] = change % 500;

	coin[1] = change2[0] / 100;
	change2[1] = change2[0] % 100;

	coin[2] = change2[1] / 50;
	change2[2] = change2[1] % 50;

	coin[3] = change2[2] / 10;
	
	printf("�Ž�����\n500��: %d��\n100��: %d��\n50��: %d��\n10��: %d��", coin[0], coin[1], coin[2], coin[3]);

}