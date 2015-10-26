#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
using namespace std;

int main() {
	int testCase;

	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	cin >> testCase;

	for (int p = 1; p <= testCase; p++) {
		int cnt, jump, frog = 0, jumpCnt = 0;
		int* arr;

		cin >> cnt;
		arr = new int[cnt];

		for (int i = 0; i < cnt; i++)
			cin >> arr[i];

		cin >> jump;

		cout << "Case #" << p << endl;

		int pos = 0;
		int arrPos = 0;
		int state = jump + pos;
		int temp = 0;

		while (pos < arr[cnt - 1]) {
			while (arr[arrPos] <= state && cnt > arrPos)
				arrPos++;

			if (temp == arrPos) {
				jumpCnt = 0;
				break;
			}
			jumpCnt++;
			temp = arrPos;
			pos = arr[arrPos - 1];
			state = jump + pos;
		}

		if (jumpCnt != 0)
			cout << jumpCnt << endl;
		else
			cout << -1 << endl;

		delete []arr;
	}
	return 0;
}