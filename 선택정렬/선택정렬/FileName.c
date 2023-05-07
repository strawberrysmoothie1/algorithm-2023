#include <stdio.h>

void Selection(int* num, int n, int k)// ���� ���� �Լ�
{
    if (n <= 1) {
        return;
    }

    int p = num[n / 2];
    int S = 0;
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
    

    // pivot�� k��° ���� ���� ���
    if (k == i) {
        return;
    }
    // k�� ���� pivot�� �������� ���� �κ� �迭�� ���ϴ� ���
    else if (k < i) {
        Selection(num, i - 1, k);
    }
    // k�� ���� pivot�� �������� ������ �κ� �迭�� ���ϴ� ���
    else {
        Selection(num + i, n - i, k - i);
    }
}

int main() {
    int n = 0;
    int num[100];
    int k = 0;
    printf("�Է��� ���� ����: ");
    scanf("%d", &n);

    printf("������ k��°�� ����");
    scanf("%d", &k);
    if (k > n) {
        printf("�߸��� �Է�");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        printf("���� �Է�: ");
        scanf("%d", &num[i]);
    }

    printf("�Է��� ����: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", num[i]);
    }

    Selection(num, n, k);

    
    printf("\nk��°�� ���� ��: %d", num[k-1]);

    return 0;
}
