#include <stdio.h>

void Quick(int* num, int n)// �� ���� �Լ�
{
    if (n <= 1) {
        return;
    }

    int p = num[n / 2];

    int i = 0, j = n - 1; // �迭�� ó���� ���������� �����ϴ� �ε���

    while (i <= j) {  // i�� j �ε����� ������ ������ �ݺ�
        while (num[i] < p) { // pivot ������ ū ���� �������� i �ε��� �̵�
            i++;
        }
        while (num[j] > p) { // pivot ������ ���� ���� �������� j �ε��� �̵�
            j--;
        }

        if (i <= j) { // i�� j �ε����� ������ ��� �ݺ��� ����
            int tmp = num[i]; // i�� j �ε����� ����Ű�� �� swap
            num[i] = num[j];
            num[j] = tmp;
            i++;
            j--;
        }
    }
    // �Ǻ��� �������� ���ҵ� �� ���� �κ� �迭�� ���� Quick �Լ� ���ȣ��
    Quick(num, j + 1);
    Quick(num + i, n - i);
}

int main() {
    int n = 0;
    int num[100];

    printf("�Է��� ���� ����: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("���� �Է�: ");
        scanf("%d", &num[i]);
    }

    printf("�Է��� ����: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", num[i]);
    }

    Quick(num, n);

    printf("\n���ĵ� ����: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", num[i]);
    }

    return 0;
}
