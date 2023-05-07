#include <stdio.h>

#define MAX_SIZE 100000

void mergesort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // �߰����� ����

        mergesort(arr, left, mid); // ���� �迭�� ����
        mergesort(arr, mid + 1, right); // ������ �迭�� ����

        merge(arr, left, mid, right); // �� ���� �迭�� ��ġ��
    }
}

int main() {
    FILE* input, * output;
    int arr[MAX_SIZE], n = 0; // �Է� �����͸� ������ �迭�� �迭�� ũ��

    input = fopen("data.txt", "r"); // �Է� ���� ����
    output = fopen("result.txt", "w"); // ��� ���� ����

    // ���Ͽ��� ���� �о���̱�
    while (fscanf(input, "%d", &arr[n]) != EOF) {
        n++;
    }

    mergesort(arr, 0, n - 1); // �պ� ���� �Լ� ȣ��

    // ���ĵ� ����� ��� ���Ͽ� ����
    for (int i = 0; i < n; i++) {
        fprintf(output, "%d ", arr[i]);
    }

    fclose(input); // �Է� ���� �ݱ�
    fclose(output); // ��� ���� �ݱ�

    return 0;
}