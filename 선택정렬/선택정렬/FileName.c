#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000

// �迭���� �� ������ ��ġ�� �ٲ��ִ� �Լ�
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// ������ �����ϴ� �Լ�
int partition(int arr[], int left, int right) {
    int pivot = arr[right]; // pivot�� �迭�� ������ ���ҷ� ����
    int i = left - 1; // i�� pivot���� ���� ���ҵ��� �� �ε���

    // pivot�� �������� �迭�� ����
    for (int j = left; j < right; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[right]); // pivot�� �ڽź��� ���� ���ҵ��� �� �������� �̵�

    return i + 1; // pivot�� ��ġ�� ��ȯ
}

// ���� ������ �ذ��ϴ� �Լ�
int select(int arr[], int left, int right, int k) {
    if (left == right) { // �迭�� ���̰� 1�� ���, ù ��° ���Ҹ� ��ȯ
        return arr[left];
    }

    int pivotIndex = partition(arr, left, right); // �迭�� �����Ͽ� pivot�� ��ġ�� ����
    int length = pivotIndex - left + 1; // pivot�� ������ ���� �κ� �迭�� ����

    if (k == length) { // k�� ���� �κ� �迭�� ���̿� ������ pivot�� ��ȯ
        return arr[pivotIndex];
    }
    else if (k < length) { // k�� ���� �κ� �迭�� ���̺��� ������ ���� �κ� �迭���� k��° ���� ���Ҹ� ã��
        return select(arr, left, pivotIndex - 1, k);
    }
    else { // k�� ���� �κ� �迭�� ���̺��� ũ�� ������ �κ� �迭���� (k - ���� �κ� �迭�� ����)��° ���� ���Ҹ� ã��
        return select(arr, pivotIndex + 1, right, k - length);
    }
}

int main() {
    int arr[MAX_SIZE];
    int n, k;

    // �Է� �ޱ�
    FILE* fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("data.txt ���� ���� ����\n");
        return 1; // ���α׷� ����
    }

    fscanf(fp, "%d", &n); // �迭�� ���̸� �Է� ����

    for (int i = 0; i < n; i++) { // �迭�� ���ҵ��� �Է� ����
        fscanf(fp, "%d", &arr[i]);
    }

    fscanf(fp, "%d", &k); // k�� �Է� ����

    fclose(fp);

    // ���� ���� �ذ��ϱ�
    int result = select(arr, 0, n - 1, k);

    // ��� ����ϱ�
    fp = fopen("result.txt", "w");
    if (fp == NULL) {
        printf("result.txt ���� ���� ����\n");
        return 1;
    }

    fprintf(fp, "%d", result);

    fclose(fp);

    return 0;
}