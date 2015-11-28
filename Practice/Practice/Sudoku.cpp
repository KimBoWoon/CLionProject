//
// Created by bw on 15. 11. 9.
//

#include <stdio.h>
//#include <Windows.h>

#pragma warning(disable:4996)

int isAvailable(int puzzle[][9], int row, int col, int num) {
	int rowStart = (row / 3) * 3;
	int colStart = (col / 3) * 3;
	int i, j;

	for (i = 0; i < 9; ++i) {
		if (puzzle[row][i] == num)
			return 0;
		if (puzzle[i][col] == num)
			return 0;
		if (puzzle[rowStart + (i % 3)][colStart + (i / 3)] == num)
			return 0;
	}
	return 1;
}

int fillSudoku(int puzzle[][9], int row, int col) {
	int i;
	if (row < 9 && col < 9) {
		if (puzzle[row][col] != 0) {
			if ((col + 1) < 9)
				return fillSudoku(puzzle, row, col + 1);
			else if ((row + 1) < 9)
				return fillSudoku(puzzle, row + 1, 0);
			else
				return 1;
		}
		else {
			for (i = 0; i < 9; ++i) {
				if (isAvailable(puzzle, row, col, i + 1)) {
					puzzle[row][col] = i + 1;
					if ((col + 1) < 9) {
						if (fillSudoku(puzzle, row, col + 1))
							return 1;
						else
							puzzle[row][col] = 0;
					}
					else if ((row + 1) < 9) {
						if (fillSudoku(puzzle, row + 1, 0))
							return 1;
						else
							puzzle[row][col] = 0;
					}
					else
						return 1;
				}
			}
		}
		return 0;
	}
	else
		return 1;
}

int main() {
	int i, j, testCase;
	int puzzle[9][9];
	//LARGE_INTEGER start_time, finish_time, liFrequency;

	//QueryPerformanceFrequency(&liFrequency);

	freopen("input.txt", "r", stdin);

	scanf("%d", &testCase);

	while (testCase--) {
		for (i = 0; i < 9; i++) {
			for (j = 0; j < 9; j++)
				scanf("%d", &puzzle[i][j]);
		}

		//QueryPerformanceCounter(&start_time);
		if (fillSudoku(puzzle, 0, 0)) {
			for (i = 1; i < 10; ++i) {
				for (j = 1; j < 10; ++j)
					printf("%d ", puzzle[i - 1][j - 1]);
				printf("\n");
			}
		}
		else
			printf("NO SOLUTION");
		//QueryPerformanceCounter(&finish_time);

		//printf("Time : %f\n", (double)(finish_time.QuadPart - start_time.QuadPart) / (double)liFrequency.QuadPart);
	}

	return 0;
}