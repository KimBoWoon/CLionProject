//
// Created by bw on 15. 11. 9.
//

#include <stdlib.h>
#include <stdio.h>

#define N 4
int col[N];

void printNqueens() {
    int i;

    for (i = 0; i < N; i++)
        printf("%d ", col[i]);
    printf("\n");
}

int isPromising(int row) {
    int k;
    int promising;
    k = 0;
    promising = 1;
    while (k < row && promising) {
        if (col[row] == col[k] || abs(col[row] - col[k]) == row - k)
            promising = 0;
        k++;
    }
    return promising;
}

void nQueens(int row) {
    int i;
    if (isPromising(row)) {
        if (row == N - 1)
            printNqueens();
        else
            for (i = 0; i < N; i++) {
                col[row + 1] = i;
                nQueens(row + 1);
            }
    }
}

int main() {
    int i;
    for (i = 0; i < N; i++) {
        col[0] = i;
        nQueens(0);
    }
}