#include <stdio.h>

#define MAX_SIZE 100000

void mergesort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // 중간값을 구함

        mergesort(arr, left, mid); // 왼쪽 배열을 정렬
        mergesort(arr, mid + 1, right); // 오른쪽 배열을 정렬

        merge(arr, left, mid, right); // 두 개의 배열을 합치기
    }
}

int main() {
    FILE* input, * output;
    int arr[MAX_SIZE], n = 0; // 입력 데이터를 저장할 배열과 배열의 크기

    input = fopen("data.txt", "r"); // 입력 파일 열기
    output = fopen("result.txt", "w"); // 출력 파일 열기

    // 파일에서 정수 읽어들이기
    while (fscanf(input, "%d", &arr[n]) != EOF) {
        n++;
    }

    mergesort(arr, 0, n - 1); // 합병 정렬 함수 호출

    // 정렬된 결과를 출력 파일에 저장
    for (int i = 0; i < n; i++) {
        fprintf(output, "%d ", arr[i]);
    }

    fclose(input); // 입력 파일 닫기
    fclose(output); // 출력 파일 닫기

    return 0;
}