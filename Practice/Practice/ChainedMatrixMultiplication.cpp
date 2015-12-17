//
// Created by bw on 15. 12. 15.
//

#include <iostream>
#include <string.h>

#define MAX_SIZE 7
using namespace std;

int minmult();

void order(int i, int j);

int d[MAX_SIZE] = {5, 2, 3, 4, 6, 7, 8};
int p[MAX_SIZE][MAX_SIZE] = {0};
int n = 6;

int main() {
    minmult();
    order(1, 6);
}

int minmult() {
    // n : 행렬 수
    // d : 행렬의 크기
    // -> 2 x 3 행렬과 3 x 4 행렬이라면 d0 = 2 d1 = 3 d3 = 4
    // p : 행렬들 사이에서 가장 작은 값이 나오는 위치
    int i, j, k, diagonal;
    int M[MAX_SIZE][MAX_SIZE];
    int min;

    memset(M, 0, sizeof(int) * MAX_SIZE * MAX_SIZE);

    for (i = 1; i <= n; i++) {
        M[i][i] = 0;
    }

    for (diagonal = 1; diagonal <= n - 1; diagonal++) {
        for (i = 1; i <= n - diagonal; i++) {
            j = i + diagonal;
            min = M[i][i] + M[i + 1][j] + d[i - 1] * d[i] * d[j];
            p[i][j] = i;

            for (k = i + 1; k < j; k++) {
                if (min > M[i][k] + M[k + 1][j] + d[i - 1] * d[k] * d[j]) {
                    min = M[i][k] + M[k + 1][j] + d[i - 1] * d[k] * d[j];
                    p[i][j] = k;
                }
            }
            M[i][j] = min;
        }
    }
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++)
            cout << M[i][j] << " ";
        cout << endl;
    }
    return M[1][n];
}

void order(int i, int j) {
    // 출력
    int k;

    if (i == j)
        cout << "A" << i;

    else {
        k = p[i][j];

        cout << "(";
        order(i, k);
        order(k + 1, j);
        cout << ")";
    }
}