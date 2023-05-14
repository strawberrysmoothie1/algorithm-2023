#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000

// 배열에서 두 원소의 위치를 바꿔주는 함수
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 분할을 수행하는 함수
int partition(int arr[], int left, int right) {
    int pivot = arr[right]; // pivot은 배열의 마지막 원소로 선택
    int i = left - 1; // i는 pivot보다 작은 원소들의 끝 인덱스

    // pivot을 기준으로 배열을 분할
    for (int j = left; j < right; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[right]); // pivot을 자신보다 작은 원소들의 끝 다음으로 이동

    return i + 1; // pivot의 위치를 반환
}

// 선택 문제를 해결하는 함수
int select(int arr[], int left, int right, int k) {
    if (left == right) { // 배열의 길이가 1인 경우, 첫 번째 원소를 반환
        return arr[left];
    }

    int pivotIndex = partition(arr, left, right); // 배열을 분할하여 pivot의 위치를 구함
    int length = pivotIndex - left + 1; // pivot을 포함한 왼쪽 부분 배열의 길이

    if (k == length) { // k가 왼쪽 부분 배열의 길이와 같으면 pivot을 반환
        return arr[pivotIndex];
    }
    else if (k < length) { // k가 왼쪽 부분 배열의 길이보다 작으면 왼쪽 부분 배열에서 k번째 작은 원소를 찾음
        return select(arr, left, pivotIndex - 1, k);
    }
    else { // k가 왼쪽 부분 배열의 길이보다 크면 오른쪽 부분 배열에서 (k - 왼쪽 부분 배열의 길이)번째 작은 원소를 찾음
        return select(arr, pivotIndex + 1, right, k - length);
    }
}

int main() {
    int arr[MAX_SIZE];
    int n, k;

    // 입력 받기
    FILE* fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("data.txt 파일 열기 실패\n");
        return 1; // 프로그램 종료
    }

    fscanf(fp, "%d", &n); // 배열의 길이를 입력 받음

    for (int i = 0; i < n; i++) { // 배열의 원소들을 입력 받음
        fscanf(fp, "%d", &arr[i]);
    }

    fscanf(fp, "%d", &k); // k를 입력 받음

    fclose(fp);

    // 선택 문제 해결하기
    int result = select(arr, 0, n - 1, k);

    // 결과 출력하기
    fp = fopen("result.txt", "w");
    if (fp == NULL) {
        printf("result.txt 파일 열기 실패\n");
        return 1;
    }

    fprintf(fp, "%d", result);

    fclose(fp);

    return 0;
}