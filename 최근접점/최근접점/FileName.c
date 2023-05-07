#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point {
    int x;
    int y;
} Point;

double distance(Point p1, Point p2) {
    double result;
    double a, b, c;

    if (p1.x == p2.x) { // x축의 위치가 같을 경우
        result = p2.y - p1.y;
        result = fabs(result); // 절댓값 함수 fabs를 이용해 음수일 경우 대비
    }
    else if (p1.y == p2.y) { // y축의 위치가 같을 경우
        result = p2.x - p1.x;
        result = fabs(result);
    }
    else { // 피타고라스의 정리를 활용해야 하는 경우
        a = p1.x - p2.x;
        b = p1.y - p2.y;
        c = pow(a, 2) + pow(b, 2);
        result = sqrt(c);
    }
    return result;
}

double Closest_Pair(Point P[], int left, int right, Point* closestPair[])
{
    int i, j;
    // 기저 사례: 점의 개수가 3 이하인 경우, 모든 점들 사이의 거리 중 최소 거리 반환
    if (right - left <= 2)
    {
        double minDistance = 99999999;
        for (i = left; i < right; i++)
        {
            for (j = i + 1; j < right; j++) {
                double dist = distance(P[i], P[j]);
                if (dist < minDistance) {
                    minDistance = dist;
                    closestPair[0] = &P[i];
                    closestPair[1] = &P[j];
                }
            }
        }
        return minDistance;
    }
    // 중앙점 인덱스 계산
    int mid = (left + right) / 2;

    // 좌측 부분과 우측 부분에 대해 재귀적으로 최근접 점의 쌍과 거리 찾기
    Point* leftClosestPair[2];
    double minDistanceLeft = Closest_Pair(P, left, mid, leftClosestPair);
    Point* rightClosestPair[2];
    double minDistanceRight = Closest_Pair(P, mid + 1, right, rightClosestPair);

    // 좌측 부분과 우측 부분에서 찾은 최근접 점의 쌍 중에서 최소 거리 선택
    double minDistance = (minDistanceLeft < minDistanceRight) ? minDistanceLeft : minDistanceRight;
    Point** minDistancePair = (minDistanceLeft < minDistanceRight) ? leftClosestPair : rightClosestPair;

    // 가로지르는 영역에서 더 가까운 점의 쌍이 있는지 확인
    double minDistanceStrip = INFINITY;
    Point* stripPair[2];
    int stripPairCount = 0;

    for (i = left; i <= right; i++) {
        if (abs(P[i].x - P[mid].x) < minDistance) {
            for (j = i + 1; j <= right; j++) {
                if (abs(P[j].x - P[mid].x) < minDistance) {
                    double dist = distance(P[i], P[j]);
                    if (dist < minDistance) {
                        minDistance = dist;
                        stripPair[0] = &P[i];
                        stripPair[1] = &P[j];
                        stripPairCount = 1;
                    }
                    else if (dist == minDistance) {
                        if (stripPairCount < 2) {
                            stripPair[stripPairCount++] = &P[i];
                            stripPair[stripPairCount++] = &P[j];
                        }
                    }
                }
                else {
                    break;
                }
            }
        }
    }

    // 가로지르는 영역에서의 최근접 점의 쌍과 거리 중 최소값 선택
    if (stripPairCount > 0) {
        minDistancePair = stripPair;
    }

    closestPair[0] = minDistancePair[0];
    closestPair[1] = minDistancePair[1];
    return minDistance;
}

int main()
{
    int numPoints = 4;
    Point P[] = { {1, 2}, {2, 4}, {2, 9}, {3, 3} };

    Point* closestPair[2];
    Closest_Pair(P, 0, numPoints, closestPair);
    printf("최근접 점의 쌍: (%d, %d), (%d, %d)\n", closestPair[0]->x, closestPair[0]->y, closestPair[1]->x, closestPair[1]->y);

    return 0;
}