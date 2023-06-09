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

    FILE* input, * output; // 입력 파일 포인터, 출력 파일 포인터

    input = fopen("data.txt", "r"); // data.txt 파일을 읽기 모드로 열기
    output = fopen("result.txt", "w"); // result.txt 파일을 쓰기 모드로 열기

    if (input == NULL) { // 파일 열기에 실패한 경우
        printf("파일 열기 실패");
        return 0;
    }

    fscanf(input, "%d", &n); // 파일에서 숫자 개수 입력받기
    for (int i = 0; i < n; i++) {
        fscanf(input, "%d", &num[i]); // 파일에서 숫자 입력받기
    }

    fprintf(output, "입력한 숫자: ");
    for (int i = 0; i < n; i++) {
        fprintf(output, "%d ", num[i]); // 입력한 숫자 출력
    }

    Quick(num, n); // 퀵 정렬 실행

    fprintf(output, "\n정렬된 숫자: ");
    for (int i = 0; i < n; i++) {
        fprintf(output, "%d ", num[i]); // 정렬된 숫자 출력
    }

    fclose(input); // 파일 닫기
    fclose(output);

    return 0;
}