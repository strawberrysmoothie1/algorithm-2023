#include <stdio.h>

void Quick(int* num, int n)// 퀵 정렬 함수
{
    if (n <= 1) {
        return;
    }

    int p = num[n / 2];

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
    // 피봇을 기준으로 분할된 두 개의 부분 배열에 대해 Quick 함수 재귀호출
    Quick(num, j + 1);
    Quick(num + i, n - i);
}

int main() {
    int n = 0;
    int num[100];

    printf("입력할 숫자 개수: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("숫자 입력: ");
        scanf("%d", &num[i]);
    }

    printf("입력한 숫자: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", num[i]);
    }

    Quick(num, n);

    printf("\n정렬된 숫자: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", num[i]);
    }

    return 0;
}
