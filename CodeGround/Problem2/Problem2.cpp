#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int arr[1002][1002] = { 0 };
int state[1002][1002] = { 0 };
enum Direction {RIGHT = 0, LEFT, UP, DOWN};

int f(int size) {
	int x = 1, y = 1, direction = RIGHT, cnt = 0;
	
	while (true) {
		if (x < 1 || y < 1 || x > size || y > size)
			return cnt;

		if (direction == RIGHT) {
			while (arr[x][y] == 0) {
				y++;
				if (x < 1 || y < 1 || x > size || y > size)
					return cnt;
			}
			if (state[x][y] != 1)
				cnt++;
			state[x][y] = 1;
			if (arr[x][y] == 1) {
				direction = UP;
				x--;
			}
			else if (arr[x][y] == 2) {
				direction = DOWN;
				x++;
			}
		}
		else if (direction == LEFT) {
			while (arr[x][y] == 0) {
				y--;
				if (x < 1 || y < 1 || x > size || y > size)
					return cnt;
			}
			if (state[x][y] != 1)
				cnt++;
			state[x][y] = 1;
			if (arr[x][y] == 1) {
				direction = DOWN;
				x++;
			}
			else if (arr[x][y] == 2) {
				direction = UP;
				x--;
			}
		}
		else if (direction == UP) {
			while (arr[x][y] == 0) {
				x--;
				if (x < 1 || y < 1 || x > size || y > size)
					return cnt;
			}
			if (state[x][y] != 1)
				cnt++;
			state[x][y] = 1;
			if (arr[x][y] == 1) {
				direction = RIGHT;
				y++;
			}
			else if (arr[x][y] == 2) {
				direction = LEFT;
				y--;
			}
		}
		else if (direction == DOWN) {
			while (arr[x][y] == 0) {
				x++;
				if (x < 1 || y < 1 || x > size || y > size)
					return cnt;
			}
			if (state[x][y] != 1)
				cnt++;
			state[x][y] = 1;
			if (arr[x][y] == 1) {
				direction = LEFT;
				y--;
			}
			else if (arr[x][y] == 2) {
				direction = RIGHT;
				y++;
			}
		}
	}
}
int main() {
	int testCase;

	freopen("input.txt", "r", stdin);

	cin >> testCase;

	for (int p = 1; p <= testCase; p++) {
		int size;
		string str;

		cin >> size;

		cout << "Case #" << p << endl;

		for (int x = 1; x <= size; x++) {
			cin >> str;
			for (int y = 1; y <= size; y++)
				arr[x][y] = str[y - 1] - 48;
		}
		cout << f(size) << endl;
		memset(arr, 0, sizeof(int) * 1002 * 1002);
		memset(state, 0, sizeof(int) * 1002 * 1002);
	}
}