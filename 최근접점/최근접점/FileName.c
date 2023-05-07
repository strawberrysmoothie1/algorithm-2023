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

    if (p1.x == p2.x) { // x���� ��ġ�� ���� ���
        result = p2.y - p1.y;
        result = fabs(result); // ���� �Լ� fabs�� �̿��� ������ ��� ���
    }
    else if (p1.y == p2.y) { // y���� ��ġ�� ���� ���
        result = p2.x - p1.x;
        result = fabs(result);
    }
    else { // ��Ÿ����� ������ Ȱ���ؾ� �ϴ� ���
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
    // ���� ���: ���� ������ 3 ������ ���, ��� ���� ������ �Ÿ� �� �ּ� �Ÿ� ��ȯ
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
    // �߾��� �ε��� ���
    int mid = (left + right) / 2;

    // ���� �κа� ���� �κп� ���� ��������� �ֱ��� ���� �ְ� �Ÿ� ã��
    Point* leftClosestPair[2];
    double minDistanceLeft = Closest_Pair(P, left, mid, leftClosestPair);
    Point* rightClosestPair[2];
    double minDistanceRight = Closest_Pair(P, mid + 1, right, rightClosestPair);

    // ���� �κа� ���� �κп��� ã�� �ֱ��� ���� �� �߿��� �ּ� �Ÿ� ����
    double minDistance = (minDistanceLeft < minDistanceRight) ? minDistanceLeft : minDistanceRight;
    Point** minDistancePair = (minDistanceLeft < minDistanceRight) ? leftClosestPair : rightClosestPair;

    // ���������� �������� �� ����� ���� ���� �ִ��� Ȯ��
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

    // ���������� ���������� �ֱ��� ���� �ְ� �Ÿ� �� �ּҰ� ����
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
    printf("�ֱ��� ���� ��: (%d, %d), (%d, %d)\n", closestPair[0]->x, closestPair[0]->y, closestPair[1]->x, closestPair[1]->y);

    return 0;
}