#include <stdio.h>

void Selection(int* num, int n, int k) // 선택 정렬 함수
{
    if (n <= 1) {
        return;
    }

    int p = num[n / 2];
    int S = 0;
    int i = 0, j = n - 1; // 배열의 처음과 끝에서부터 시작하는 인덱스

    while (i <= j) {  // i와 j 인덱스가 엇갈릴 때까지 반복
        while (num[i] < p) { // pivot 값보다 큰 값이 나오도록 i 인덱스 이동
            i++;
        }
        while (num[j] > p) { // pivot 값보다 작은 값이 나오도록 j 인덱스 이동
            j--;
        }

        if (i <= j) { // i와 j 인덱스가 엇갈린 경우 반복문 종료
            int tmp = num[i]; // i와 j 인덱스가 가리키는 값 swap
            num[i] = num[j];
            num[j] = tmp;
            i++;
            j--;
        }
    }

    // pivot이 k번째 작은 수인 경우
    if (k == i) {
        return;
    }
    // k가 현재 pivot을 기준으로 왼쪽 부분 배열에 속하는 경우
    else if (k < i) {
        Selection(num, i - 1, k);
    }
    // k가 현재 pivot을 기준으로 오른쪽 부분 배열에 속하는 경우
    else {
        Selection(num + i, n - i, k - i);
    }
}

int main() {
    int n = 0;
    int num[100];
    int k = 0;
    FILE* input, * output;
    input = fopen("data.txt", "r");
    output = fopen("result.txt", "w");

    fscanf(input, "%d", &n);
    fscanf(output, "%d", &k);

    if (k > n) {
        fprintf(output, "잘못된 입력");
        return 0;
    }

    for (int i = 0; i < n; i++) {
        fscanf(input, "%d", &num[i]);
    }

    fprintf(output, "입력한 숫자: ");
    for (int i = 0; i < n; i++) {
        fprintf(output, "%d ", num[i]);
    }

    Selection(num, n, k);

    fprintf(output, "\nk번째로 작은 수: %d", num[k - 1]);

    fclose(input);
    fclose(output);
    return 0;
}
